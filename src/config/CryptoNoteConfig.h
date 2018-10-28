// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018, The Plenteum Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <initializer_list>
#include <boost/uuid/uuid.hpp>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 18181; // PLe
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 20;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 3 * DIFFICULTY_TARGET;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V3         = 3 * DIFFICULTY_TARGET;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V4         = 3 * DIFFICULTY_TARGET;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = ((uint64_t)(2100000000000000000)); //21 billion, 2 Decimal places for DUST
const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                   = 0;
const size_t ZAWY_DIFFICULTY_V2                              = 1;
const uint8_t ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION       = 3;

const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX                 = 2;
const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V2              = 3;

const uint64_t LWMA_3_DIFFICULTY_BLOCK_INDEX				 = 130000; //LWMA-3 Difficulty Upgrade Height

const unsigned EMISSION_SPEED_FACTOR                         = 22;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

/* Premine amount */
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(52500000000000000); //2.5%

/* How to generate a premine:

* Compile your code

* Run zedwallet, ignore that it can't connect to the daemon, and generate an
  address. Save this and the keys somewhere safe.

* Launch the daemon with these arguments:
--print-genesis-tx --genesis-block-reward-address <premine wallet address>

For example:
Plenteumd --print-genesis-tx --genesis-block-reward-address PLEv2Fyavy8CXG8BPEbNeCHFZ1fuDCYCZ3vW5H5LXN4K2M2MHUpTENip9bbavpHvvPwb4NDkBWrNgURAd5DB38FHXWZyoBh4wW

* Take the hash printed, and replace it with the hash below in GENESIS_COINBASE_TX_HEX

* Recompile, setup your seed nodes, and start mining

* You should see your premine appear in the previously generated wallet.

*/
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff00018080d5d58c8fa15d0249c633559a0c58ef4d0e28ded22382678cb7e9dcf098f486a93b5cf2a1fffe86210130ad8ce712c3fbde17ebb34bb3671132a4d1a57210e4f0919131cb090e2139de";

/* This is the unix timestamp of the first "mined" block (technically block 2, not the genesis block)
   You can get this value by doing "print_block 2" in Plenteumd. It is used to know what timestamp
   to import from when the block height cannot be found in the node or the node is offline. */
const uint64_t GENESIS_BLOCK_TIMESTAMP                       = 1533098345;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE	 = 10000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 2; // the number of decimal points to display in the wallet and other software
const size_t   CRYPTONOTE_DUST_DECIMAL_POINT                 = 8; //the decimal places to calculate DUST up to... 

//DustFund Parameters
const uint64_t CRYPTONOTE_DUST_OUT_LIMIT					 = UINT64_C(1000000); //the limit up to which dust outs should be removed and contributed back to the dust fund
const char CRYPTONOTE_DUST_OUT_ADDRESS[]					 = "PLeafjfpaRWEXR4artCAer4yZFzeq5mRrMaLByP7Rkf3FL1URKUrBnP3ppfL6LVgz4hJYwk6DebUxZq6aQKHa8eT5f1ycM7j7d";

const uint64_t MINIMUM_FEE									 = UINT64_C(0); //0

const uint64_t MINIMUM_MIXIN                              = 0;
const uint64_t MAXIMUM_MIXIN                              = 7;

/* The heights to activate the mixin limits at */
const uint32_t MIXIN_LIMITS_V1_HEIGHT                        = 0;
const uint32_t MIXIN_LIMITS_V2_HEIGHT                        = 1;

/* The mixin to use by default with zedwallet and wallet-service */
/* DEFAULT_MIXIN_V0 is the mixin used before MIXIN_LIMITS_V1_HEIGHT is started */
const uint64_t DEFAULT_MIXIN								 = MINIMUM_MIXIN;

const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(0);
const uint64_t DEFAULT_DUST_THRESHOLD_V2                     = UINT64_C(0);

const uint32_t DUST_THRESHOLD_V2_HEIGHT                      = 1;
const uint32_t FUSION_DUST_THRESHOLD_HEIGHT_V2               = 65500;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 720;
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
const uint64_t DIFFICULTY_BLOCKS_COUNT						 = DIFFICULTY_WINDOW + 1;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 100000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
const uint64_t MAX_EXTRA_SIZE                                = 140000;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 0;
const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 2;
const uint32_t UPGRADE_HEIGHT_V4                             = 3; // Upgrade height for CN-Lite Variant 1 switch.
const uint32_t UPGRADE_HEIGHT_V5							 = 65500; // Upgrade height for DustFund V1.
const uint32_t UPGRADE_HEIGHT_V6							 = 67500; // tx & block size issue fix.

const uint32_t UPGRADE_HEIGHT_CURRENT                        = UPGRADE_HEIGHT_V6;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

/* Block heights we are going to have hard forks at */
const uint64_t FORK_HEIGHTS[] =
{
    0,
    1,
    2,
    3,
    65500, //first fork to introduce DUST fund
	67500, //tx & block size issue fix
	130000, //difficulty update and web wallet direct connect
	200000 // dustfund v2 
};

/* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK */
const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX                 = 6;

const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

/* The index in the FORK_HEIGHTS array that this version of the software will
   support. For example, if CURRENT_FORK_INDEX is 4, this version of the
   software will support the fork at 65500 blocks.

   This will default to zero if the FORK_HEIGHTS array is empty, so you don't
   need to change it manually. */
const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
/* Make sure CURRENT_FORK_INDEX is a valid index, unless FORK_HEIGHTS is empty */
static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "Plenteum";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  0;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_5						 =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  100;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  44015;
const int      RPC_DEFAULT_PORT                              =  44016;
const int      SERVICE_DEFAULT_PORT                          =  8070;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

// P2P Network Configuration Section - This defines our current P2P network version
// and the minimum version for communication between nodes
const uint8_t  P2P_CURRENT_VERSION                           = 3;
const uint8_t  P2P_MINIMUM_VERSION                           = 2; //bumped to min supported software version for peer connect
// This defines the number of versions ahead we must see peers before we start displaying
// warning messages that we need to upgrade our software.

const uint8_t  P2P_UPGRADE_WINDOW                            = 2;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 32 * 1024 * 1024; // 32 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char     LATEST_VERSION_URL[]                          = "http://latest.plenteum.com";

const static boost::uuids::uuid CRYPTONOTE_NETWORK =
{
    {  0xa2, 0x7d, 0x4b, 0x2c, 0xcf, 0x52, 0x37, 0x41, 0x35, 0xf9, 0x41, 0xa4, 0xc6, 0xa1, 0x43, 0xa1  }
};

const char* const SEED_NODES[] = {
  //add seed nodes
  "85.216.148.43:44015", //miner.care
  "95.216.184.244:44015", //Charlie
  "85.90.244.194:44015", //DeadSet
  "142.93.132.203:44015", //DO Seed3
  "206.189.124.145:44015", //DO Seed2
  "94.237.65.140:44015" //Singapore
};
} // CryptoNote
