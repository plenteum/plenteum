// Copyright (c) 2019, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#include "MainChainStorageSqlite.h"

#include <Common/FileSystemShim.h>

#include "json.hpp"

#include "CryptoNoteTools.h"

#include "sqlite3.h"

namespace CryptoNote
{
    MainChainStorageSqlite::MainChainStorageSqlite(const std::string &blocksFilename, const std::string &indexesFilename)
    {
        int resultCode = sqlite3_open(blocksFilename.c_str(), &m_db);

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to load main chain storage from " + blocksFilename + ": " + sqlite3_errmsg(m_db));
        }

        resultCode = sqlite3_exec(
                         m_db,
                         "CREATE TABLE IF NOT EXISTS `rawBlocks` ( `blockIndex` INTEGER NOT NULL DEFAULT 0 PRIMARY KEY, `rawBlock` TEXT )",
                         NULL,
                         NULL,
                         NULL
        );

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to create database table");
        }

        /* We set the sqlite3 mode to synchronous to avoid delays in writing to the DB
           this does run a small risk of corrupting the database in the event of system
           failure or process crash in some rare situations but the performance impact
           of synchronous writes is considerable and a risk we're willing to take */
        resultCode = sqlite3_exec(
                         m_db,
                         "PRAGMA synchronous = 0",
                         NULL,
                         NULL,
                         NULL
        );

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to set database PRAGMA");
        }
    }

    MainChainStorageSqlite::~MainChainStorageSqlite()
    {
        sqlite3_close(m_db);
    }

    void MainChainStorageSqlite::pushBlock(const RawBlock &rawBlock)
    {
        sqlite3_stmt *stmt;

        /* Convert the RawBlock to a json structure for easier storage */
        nlohmann::json rawBlockJson = rawBlock;

        std::string rawBlockHex = rawBlockJson.dump();

        /* We get the current count of blocks which, as we're a 0-based index
           technically gives us the next blockIndex that we're pushing into
           the database */
        const uint32_t nextBlockIndex = getBlockCount();

        const int resultCode = sqlite3_prepare_v2(m_db, "INSERT INTO rawBlocks (blockIndex, rawBlock) VALUES (?,?)", -1, &stmt, NULL);

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to prepare insert block statement");
        }

        sqlite3_bind_int(stmt, 1, nextBlockIndex);
        sqlite3_bind_text(stmt, 2, rawBlockHex.c_str(), -1, 0);

        sqlite3_step(stmt);

        sqlite3_finalize(stmt);
    }

    void MainChainStorageSqlite::popBlock()
    {
        const int resultCode = sqlite3_exec(
                                  m_db,
                                  "DELETE FROM rawBlocks WHERE blockIndex = (SELECT MAX(blockIndex) FROM rawBlocks)",
                                  NULL,
                                  NULL,
                                  NULL
        );

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to pop the last block off the database");
        }
    }

    RawBlock MainChainStorageSqlite::getBlockByIndex(uint32_t index) const
    {
        sqlite3_stmt *stmt;
        RawBlock rawBlock = {};

        /* Go get how many blocks we have in the local blockchain cache */
        const uint32_t maxBlocks = getBlockCount();

        /* As we're a 0-based index and getBlockCount() returns the total
           number of blocks in the blockchain cache we need to account for
           that when checking to see that we aren't requesting a blockindex
           that we don't have in the blockchain cache */
        if (index > (maxBlocks - 1))
        {
            throw std::runtime_error("Cannot retrieve a block at an index higher than what we have");
        }

        int resultCode = sqlite3_prepare_v2(m_db, "SELECT rawBlock FROM rawBlocks WHERE blockIndex = ? LIMIT 1", -1, &stmt, NULL);

        sqlite3_bind_int(stmt, 1, index);

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to prepare getBlockByIndex statement");
        }

        bool found = false;

        /* Loop through the results to see if we got a block back */
        while((resultCode = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            const std::string rawBlockString = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            auto j = nlohmann::json::parse(rawBlockString);
            rawBlock = j.get<RawBlock>();
            found = true;
        }

        if (resultCode != SQLITE_DONE)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to properly to retrieve rawBlock in getBlockByIndex");
        }

        sqlite3_finalize(stmt);

        /* If for some reason we did not find a block in our query results, error out
           as this likely means that the database has a data integrity issue */
        if (!found)
        {
            throw std::runtime_error("Could not find block in cache for given blockIndex");
        }

        return rawBlock;
    }

    uint32_t MainChainStorageSqlite::getBlockCount() const
    {
        sqlite3_stmt *stmt;
        size_t blockCount = 0;

        int resultCode = sqlite3_prepare_v2(m_db, "SELECT COUNT(*) AS blockCount FROM rawBlocks", -1, &stmt, NULL);

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to prepare getBlockCount statement");
        }

        while((resultCode = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            blockCount = sqlite3_column_int(stmt, 0);
        }

        if (resultCode != SQLITE_DONE)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to properly retrieve block count in getBlockCount");
        }

        sqlite3_finalize(stmt);

        return blockCount;
    }

    void MainChainStorageSqlite::clear()
    {
        const int resultCode = sqlite3_exec(
                                  m_db,
                                  "DELETE FROM rawBlocks",
                                  NULL,
                                  NULL,
                                  NULL
        );

        if (resultCode != SQLITE_OK)
        {
            sqlite3_close(m_db);
            throw std::runtime_error("Failed to delete all blocks from the database");
        }
    }

    std::unique_ptr<IMainChainStorage> createSwappedMainChainStorageSqlite(const std::string &dataDir, const Currency &currency)
    {
        fs::path blocksFilename = fs::path(dataDir) / currency.blocksFileName();
        fs::path indexesFilename = fs::path(dataDir) / currency.blockIndexesFileName();

        auto storage = std::make_unique<MainChainStorageSqlite>(blocksFilename.string() + ".sqlite3", indexesFilename.string());

        if (storage->getBlockCount() == 0)
        {
            RawBlock genesisBlock;
            genesisBlock.block = toBinaryArray(currency.genesisBlock());
            storage->pushBlock(genesisBlock);
        }

        return storage;
    }
}