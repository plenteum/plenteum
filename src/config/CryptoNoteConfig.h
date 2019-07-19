// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2018-2019, The Plenteum Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <limits>
#include <initializer_list>
#include <boost/uuid/uuid.hpp>
#include <crypto/hash.h>

namespace CryptoNote {
	namespace parameters {

		const uint64_t DIFFICULTY_TARGET = 120; // seconds

		const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER = 500000000;
		const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 500000000;
		const size_t   CRYPTONOTE_MAX_TX_SIZE = 1000000000;
		const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 18181; // PLe
		const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 20;
		const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 3 * DIFFICULTY_TARGET;
		const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2 = 6 * DIFFICULTY_TARGET;

		const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 11;

		// MONEY_SUPPLY - total number coins to be generated
		const uint64_t MONEY_SUPPLY = ((uint64_t)(2100000000000000000)); //21 billion, 2 Decimal places for DUST
		const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX = 0;
		const size_t ZAWY_DIFFICULTY_V2 = 1;
		const uint8_t ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_HEIGHT = 4;

		const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX = 2;
		const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V2 = 3;
		const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V3 = 280000; //diff adjustment

		const unsigned EMISSION_SPEED_FACTOR = 22;
		static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

		/* Premine amount */
		const uint64_t GENESIS_BLOCK_REWARD = UINT64_C(52500000000000000); //2.5%

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
		const char     GENESIS_COINBASE_TX_HEX[] = "010a01ff00018080d5d58c8fa15d0249c633559a0c58ef4d0e28ded22382678cb7e9dcf098f486a93b5cf2a1fffe86210130ad8ce712c3fbde17ebb34bb3671132a4d1a57210e4f0919131cb090e2139de";
		static_assert(sizeof(GENESIS_COINBASE_TX_HEX)/sizeof(*GENESIS_COINBASE_TX_HEX) != 1, "GENESIS_COINBASE_TX_HEX must not be empty.");
		/* This is the unix timestamp of the first "mined" block (technically block 2, not the genesis block)
		   You can get this value by doing "print_block 2" in Plenteumd. It is used to know what timestamp
		   to import from when the block height cannot be found in the node or the node is offline. */
		const uint64_t GENESIS_BLOCK_TIMESTAMP = 1533098345;

		const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;
		
		/* If you Fork PLE Please set the below value to 100000 NOT 10000 as this will fix a mistake we made at mainnetlaunch with transaction sizes */
		const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE = 10000; //size of block (bytes) after which reward for block calculated using block size
		const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 = 100000; //size of block (bytes) after which reward for block calculated using block size (fix tx sizes issue)
		const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
		const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;
		const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT = 2; // the number of decimal points to display in the wallet and other software
		const size_t   CRYPTONOTE_DUST_DECIMAL_POINT = 8; //the decimal places to calculate DUST up to... 

		//DustFund Parameters
		const uint64_t CRYPTONOTE_DUST_OUT_LIMIT = UINT64_C(1000000); //the limit up to which dust outs should be removed and contributed back to the dust fund
		const char CRYPTONOTE_DUST_OUT_ADDRESS[] = "PLeafjfpaRWEXR4artCAer4yZFzeq5mRrMaLByP7Rkf3FL1URKUrBnP3ppfL6LVgz4hJYwk6DebUxZq6aQKHa8eT5f1ycM7j7d";

		const uint64_t MINIMUM_FEE = UINT64_C(0); //0

		const uint64_t MINIMUM_MIXIN = 3;
		const uint64_t MAXIMUM_MIXIN = 12;

		const uint64_t MINIMUM_MIXIN_V1 = 0;
		const uint64_t MAXIMUM_MIXIN_V1 = 7;

		/* The heights to activate the mixin limits at */
		const uint32_t MIXIN_LIMITS_V1_HEIGHT = 400000; //height at which new Mixin Limits Kick in

		/* The mixin to use by default with zedwallet and wallet-service */
		/* DEFAULT_MIXIN_V1 is the mixin used before MIXIN_LIMITS_V1_HEIGHT is started */
		const uint64_t DEFAULT_MIXIN = MINIMUM_MIXIN;
		const uint64_t DEFAULT_MIXIN_V1 = MINIMUM_MIXIN_V1;

		const uint64_t DEFAULT_DUST_THRESHOLD = UINT64_C(0);
		const uint64_t DEFAULT_DUST_THRESHOLD_V2 = UINT64_C(0);

		const uint32_t DUST_THRESHOLD_V2_HEIGHT = 1;
		const uint32_t FUSION_DUST_THRESHOLD_HEIGHT_V2 = 200;

		const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 24 * 60 * 60 / DIFFICULTY_TARGET;
		const size_t   DIFFICULTY_WINDOW = 60;
		const size_t   DIFFICULTY_WINDOW_V1 = 720;
		const size_t   DIFFICULTY_CUT = 5;  // timestamps to cut after sorting
		const size_t   DIFFICULTY_CUT_V1 = 60;  // timestamps to cut after sorting
		const size_t   DIFFICULTY_LAG = 5;  // !!!
		const size_t   DIFFICULTY_LAG_V1 = 15;  // !!!
		const uint64_t DIFFICULTY_BLOCKS_COUNT = DIFFICULTY_WINDOW + DIFFICULTY_LAG;

		static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

		const size_t   MAX_BLOCK_SIZE_INITIAL = 100000;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR = 100 * 1024;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
		const uint64_t MAX_EXTRA_SIZE = 140000;
		const uint64_t MAX_EXTRA_SIZE_V2 = 10240;
		const uint64_t MAX_EXTRA_SIZE_V2_HEIGHT = 280000; //height at which tx extra is limited to 10240

		/* For new projects forked from this code base, the values immediately below
   should be changed to 0 to prevent issues with transaction processing
   and other possible unexpected behavior */
		const uint64_t TRANSACTION_SIGNATURE_COUNT_VALIDATION_HEIGHT = 280000; //UPGRADE HEIGHT
		const uint64_t BLOCK_BLOB_SHUFFLE_CHECK_HEIGHT = 280000; //UPGRADE HEIGHT
        const uint64_t TRANSACTION_INPUT_BLOCKTIME_VALIDATION_HEIGHT = 280000; //UPGRADE HEIGHT

		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS = 1;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

		const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME = 60 * 60 * 24;     //seconds, one day
		const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
		const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

		const size_t   FUSION_TX_MAX_SIZE = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
		const size_t   FUSION_TX_MIN_INPUT_COUNT = 12;
		const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO = 4;

		const uint32_t UPGRADE_HEIGHT_V2 = 1;
		const uint32_t UPGRADE_HEIGHT_V3 = 2;
		const uint32_t UPGRADE_HEIGHT_V4 = 3; // Upgrade height for CN-Lite Variant 1 switch.
		const uint32_t UPGRADE_HEIGHT_V5 = 65500; // Upgrade height for DustFund V1.
		const uint32_t UPGRADE_HEIGHT_V6 = 67500;  //fix tx sizes issues
		const uint32_t UPGRADE_HEIGHT_V7 = 130000;  //CN Turtle

		const uint32_t UPGRADE_HEIGHT_CURRENT = UPGRADE_HEIGHT_V7;
		const unsigned UPGRADE_VOTING_THRESHOLD = 90;               // percent
		const uint32_t UPGRADE_VOTING_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
		const uint32_t UPGRADE_WINDOW = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
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
			67500, //fix tx sizes issue
			130000, // CN Turtle
			280000, //Difficulty Update
			400000, // mixin limits reset
			500000 // next fork height (dust v2 & net protect)
		};

		/* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK */
		const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX = 8; //supports up to diff update

		const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

		/* The index in the FORK_HEIGHTS array that this version of the software will
		   support. For example, if CURRENT_FORK_INDEX is 4, this version of the
		   software will support the fork at 200 blocks.

		   This will default to zero if the FORK_HEIGHTS array is empty, so you don't
		   need to change it manually. */
		const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

		static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
		/* Make sure CURRENT_FORK_INDEX is a valid index, unless FORK_HEIGHTS is empty */
		static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

		const char     CRYPTONOTE_BLOCKS_FILENAME[] = "blocks.bin";
		const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[] = "blockindexes.bin";
		const char     CRYPTONOTE_POOLDATA_FILENAME[] = "poolstate.bin";
		const char     P2P_NET_DATA_FILENAME[] = "p2pstate.bin";
		const char     MINER_CONFIG_FILE_NAME[] = "miner_conf.json";
	} // parameters

	const char     CRYPTONOTE_NAME[] = "Plenteum";
	
	const uint8_t  TRANSACTION_VERSION_1 = 1;
	const uint8_t  TRANSACTION_VERSION_2 = 2;
	const uint8_t  CURRENT_TRANSACTION_VERSION = TRANSACTION_VERSION_1;
	const uint8_t  BLOCK_MAJOR_VERSION_0 = 0;
	const uint8_t  BLOCK_MAJOR_VERSION_1 = 1;
	const uint8_t  BLOCK_MAJOR_VERSION_2 = 2;
	const uint8_t  BLOCK_MAJOR_VERSION_3 = 3;
	const uint8_t  BLOCK_MAJOR_VERSION_4 = 4; //block version to fix tx sizes issue
	const uint8_t  BLOCK_MAJOR_VERSION_5 = 5; //algo change to CN Turtle
	
	const uint8_t  BLOCK_MINOR_VERSION_0 = 0;
	const uint8_t  BLOCK_MINOR_VERSION_1 = 1;

	const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000;  //by default, blocks ids count in synchronizing
	const uint64_t BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 100;    //by default, blocks count in blocks downloading
	const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;

	const int      P2P_DEFAULT_PORT = 44015;
	const int      RPC_DEFAULT_PORT = 44016;
	const int      SERVICE_DEFAULT_PORT = 8070;

	const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;
	const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;

	// P2P Network Configuration Section - This defines our current P2P network version
	// and the minimum version for communication between nodes
	const uint8_t  P2P_CURRENT_VERSION = 5; //bump p2p version 
	const uint8_t  P2P_MINIMUM_VERSION = 4; //bump min supported version
const std::unordered_map<
    uint8_t,
    std::function<void(const void *data, size_t length, Crypto::Hash &hash)>
> HASHING_ALGORITHMS_BY_BLOCK_VERSION =
{
    { BLOCK_MAJOR_VERSION_0, Crypto::cn_slow_hash_v0 },             /* From zero */
	{ BLOCK_MAJOR_VERSION_1, Crypto::cn_slow_hash_v0 },             /* UPGRADE_HEIGHT_V1 */
    { BLOCK_MAJOR_VERSION_2, Crypto::cn_slow_hash_v0 },             /* UPGRADE_HEIGHT_V2 */
    { BLOCK_MAJOR_VERSION_3, Crypto::cn_lite_slow_hash_v1 },        /* UPGRADE_HEIGHT_V3 */
    { BLOCK_MAJOR_VERSION_4, Crypto::cn_lite_slow_hash_v1 },        /* UPGRADE_HEIGHT_V4 */
    { BLOCK_MAJOR_VERSION_5, Crypto::cn_turtle_lite_slow_hash_v2 }  /* UPGRADE_HEIGHT_V5 */
};

	// This defines the minimum P2P version required for lite blocks propogation
	const uint8_t  P2P_LITE_BLOCKS_PROPOGATION_VERSION = 4;

	// This defines the number of versions ahead we must see peers before we start displaying
	// warning messages that we need to upgrade our software.

	const uint8_t  P2P_UPGRADE_WINDOW = 1;

	const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 32 * 1024 * 1024; // 32 MB
	const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT = 8;
	const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70;
	const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL = 60;            // seconds
	const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE = 50000000;      // 50000000 bytes maximum packet size
	const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;
	const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT = 5000;          // 5 seconds
	const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000;          // 2 seconds
	const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT = 60 * 2 * 1000; // 2 minutes
	const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 5000;          // 5 seconds
	const char     P2P_STAT_TRUSTED_PUB_KEY[] = "";

	const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE = 1024;
	const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE = 1024;
	const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES = 500;
	const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT = 10;

	const char     LATEST_VERSION_URL[] = "https://www.plenteum.com/latest";
	const std::string LICENSE_URL = "https://github.com/plenteum/plenteum/blob/master/LICENSE";
	const static boost::uuids::uuid CRYPTONOTE_NETWORK =
	{
		{  0xa2, 0x7d, 0x4b, 0x2c, 0xcf, 0x52, 0x37, 0x41, 0x35, 0xf9, 0x41, 0xa4, 0xc6, 0xa1, 0x43, 0xa1  }
	};

	const char* const SEED_NODES[] = {
		//add seed nodes
		"miner.care:44015", //miner.care
		"one.public.plenteum.com:44015", //Charlie
		"ple.optimusblue.com:44015", //DeadSet
		"three.seed.plenteum.com:44015", //DO Seed3
		"two.seed.plenteum.com:44015", //DO Seed2
		"four.seed.plenteum.com:44015" //Seed 4
	};
} // CryptoNote
