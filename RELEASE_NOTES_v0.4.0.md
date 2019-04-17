#### Special Notes

Please note, the build directions have changed, refer to the main [Readme](https://github.com/plenteum/plenteum/blob/master/README.md) for instructions.

### Upgrade to this release is required

### Network Upgrade at Block 205,000
	
The v0.4.0 release of the core Plenteum software activates a network upgrade at block 205,000 that includes the following:

- changed the difficulty algorithm parameters to allow for much faster network hashrate updates when large volumes of hash rate join or leave the network. 
- forces the verification of the signature counts on transactions send throughout the network. 
- helps reduce the risk of blockchain bloat from malformed transactions. 
- restricts transaction extra to a maximum of 1,0240 bytes to prevent chain storage bloat.
- activates logic immediately that stops transactions exceeding this size limit from entering the transaction pool or being selected during the getblocktemplate calls; however, until block 205,000 transactions included in a block may still have transaction extra data exceeding the 1,0240 byte limit. 

Pools, miners, and services can do their part by upgrading their daemons as soon as possible.

#### Release Notes

### General Updates
- Implements fork at 205,000 to reject new transactions with TX_EXTRA data > 1,0240 bytes and to reject new transactions where the signature count is incorrect for the number of inputs in the transaction
- Renamed PAGE_SIZE parameter in slow-hash functions that was causing errors when building for some users
- Activated compiler cache for AppVeyor CI builds
- Resolved a few edge case bugs whereby block synchronization may fall-through to different code paths
- Resolved issue in AARCH64 builds that prevent the daemon from syncing to 100% height
- Improved Mnemonics compilation speed
- Resolved locale specific issue in Windows error messages
- Updated to use platform independent randomness sources
- Limits TX_EXTRA data field on transactions to <= 1,0240 bytes
- CN Soft Shell algorithm altered (as yet unused by Plenteum) to allow for the user of CPU/GPU mining software
- Removed all references to LWMA3 from the codebase to avoid any confusion about Difficulty algorithms in use
- Resolved issue in some OSX build environments where building with the latest Xcode failed

### Plenteumd Updates
- Update core software to allow difficulty updates to NOT reply on block major version
- Resolved issue regarding consistent logging
- Increased the log level of the daemon when existing to provide insight and better error reporting when the daemon appears to hang while exiting.
- Resolved issue with imprecision in fork countdown in status command
- Added optional blockCount parameter to getwalletsyncdata method
- Resolved various issues regarding Lite Blocks propagation. Thanks @michael-herwig.

### zedwallet Updates
- N/A

### zedwallet-beta Updates
- Replaced wallet saving/loading with rapidjson library.
- Optimized synchronization flow logic
- Resolved edge case where wallet crashes when using a view wallet
- Added the ability to return the transaction private key of a transaction you have sent. If you reset or rebuild your wallet, this option will not work.
- Added additional logging facilities
- Resolved issue with the display of the future unlock time in the UI if the input is locked as it comes in.

### wallet-service Updates
- Restored -l CLI argument for the --log-file option

### wallet-api Updates
- Added /balances endpoint
- Added optional unlock time parameter to /send/advanced endpoint
- Now returns the privateSpendKey when creating a new address
- Replaced wallet saving/loading with rapidjson library.
- Resolved an error whereby two wallet-api instances attempted to share the same bind port and address
- Optimized synchronization flow logic
- Various bug fixes to improve stability and overall experience
- Resolved edge case where wallet crashes when using a view wallet
- Added new /address/validate endpoint
- Enhanced endpoints to allow the wallet to be open or closed depending on the endpoint used
- Added additional logging facilities
- Added publicSpendKey to /addresses/create
- Now performs additional validation of parameters on numerous endpoint calls

### miner Updates
- N/A

#### cryptotest Updates
- Cleaned up and optimized duplicated code
- Added benchmarks for underivePublicKey and generateKeyDerivation

#### How To Sync Quickly
Download the latest checkpoints.csv here https://github.com/plenteum/checkpoints/raw/master/checkpoints.csv
Place checkpoints.csv in the same folder as your Plenteumd daemon
Run Plenteumd with checkpoints added like this:
Linux, Apple ./Plenteumd --load-checkpoints checkpoints.csv
Windows Plenteumd.exe --load-checkpoints checkpoints.csv

#### Thanks
Cryptonote Developers, Bytecoin Developers, Forknote Project, TurtleCoin Developers and the Plenteum Community