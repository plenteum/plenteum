![logo_small_flat](https://user-images.githubusercontent.com/38456463/43392866-43c69cf4-93f5-11e8-81e2-3e3f81b6ca1d.png)

[![Build status](https://ci.appveyor.com/api/projects/status/b5v5l8ta4rcqgt8r?svg=true)](https://ci.appveyor.com/project/plenteum/plenteum)

### What is Plenteum

Plenteum is a cryptonote based coin that aims to solve (at least) two significant problems in current implementations. 
  1. Sustainability of future mining rewards
  2. Dust bloat in the blockchain and user wallets

How do we do this? By removing fees from the blockchain, and accumulating a "DustFund" from transaction dust, instead of fees, we sustain the future viability of mining rewards, and lighten the chain for current transactions. 
Further info available on our website soon!

### How To Compile

On Linux or Mac on a non standard architecture, and can't get GNU Readline installed?

Disable it with `cmake .. -DFORCE_READLINE=FALSE`

#### Ubuntu 16.04+ and MacOS 10.10+

There is a bash installation script for Ubuntu 16.04+ and MacOS 10.10+ which can be used to checkout and build the project from source:

`$ curl -sL "https://raw.githubusercontent.com/plenteum/plenteum/master/scripts/multi_installer.sh" | bash `

On Ubuntu you will be asked for sudo rights to install software. The binaries will be in `./src` after compilation is complete.

This script can be used from inside the git repository to build the project from the checked out source, `./multi_installer.sh`

See the script for more installation details and please consider extending it for your operating system and distribution!

If the script doesn't work for you:

#### Linux

##### Prerequisites

- You will need the following packages: boost (1.55 or higher), rocksdb, cmake, git, gcc (4.9 or higher), g++ (4.9 or higher), make, GNU readline, and python. Most of these should already be installed on your system.
- For example on Ubuntu: `sudo apt-get install -y build-essential python-dev gcc g++ git cmake libboost-all-dev librocksdb-dev libreadline-dev`
- If you are using Ubuntu and your version of Ubuntu doesn't have librocksdb-dev, you can get it from a ppa instead:
```
sudo add-apt-repository ppa:ethcore/ethcore -y
sudo apt-get update
sudo apt-get install librocksdb-dev
```

##### Building

- `git clone -b master https://github.com/plenteum/plenteum`
- `cd plenteum`
- `mkdir build && cd $_`
- `cmake ..`
- `make`

If you're receiving a permission denied error running `cmake ..` on ubuntu, then you need to give execute permission to the version.sh file in rocksdb by running `sudo chmod +x external/rocksdb/build_tools/version.sh`

#### Apple

##### Prerequisites

- Install [cmake](https://cmake.org/). See [here](https://stackoverflow.com/questions/23849962/cmake-installer-for-mac-fails-to-create-usr-bin-symlinks) if you are unable call `cmake` from the terminal after installing.
- Install the [boost](http://www.boost.org/) libraries. Either compile boost manually or run `brew install boost`.
- Install [GNU Readline](https://tiswww.case.edu/php/chet/readline/rltop.html) by running `brew install readline; brew link --force readline`. - Make sure you run this full command, or it will link the wrong version of readline
- Install XCode and Developer Tools.

##### Building

- `git clone -b master https://github.com/plenteum/plenteum`
- `cd plenteum`
- `mkdir build && cd $_`
- `cmake ..` or `cmake -DBOOST_ROOT=<path_to_boost_install> ..` when building
  from a specific boost install. If you used brew to install boost, your path is most likely `/usr/local/include/boost.`
- `make`

The binaries will be in `./src` after compilation is complete.

Run `./src/Plenteumd` to connect to the network and let it sync (it may take a while).

#### Windows 10

##### Prerequisites
- Install [Visual Studio 2017 Community Edition](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&page=inlineinstall)
- When installing Visual Studio, it is **required** that you install **Desktop development with C++** and the **VC++ v140 toolchain** when selecting features. The option to install the v140 toolchain can be found by expanding the "Desktop development with C++" node on the right. You will need this for the project to build correctly.
- Install [Boost 1.59.0](https://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/), ensuring you download the installer for MSVC 14.

##### Building

- From the start menu, open 'x64 Native Tools Command Prompt for vs2017'.
- `cd <your_plenteum_directory>`
- `mkdir build`
- `cd build`
- Set the PATH variable for cmake: ie. `set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%`
- `cmake -G "Visual Studio 14 Win64" .. -DBOOST_ROOT=C:/local/boost_1_59_0` (Or your boost installed dir.)
- `MSBuild Plenteum.sln /p:Configuration=Release /m`
- If all went well, it will complete successfully, and you will find all your binaries in the '..\build\src\Release' directory.
- Additionally, a `.sln` file will have been created in the `build` directory. If you wish to open the project in Visual Studio with this, you can.
### Mining

Read the guide by [@Charlie](https://virtopia.ca/how-to-mine-plenteum/)

### Support

Join our discord [here](https://discord.gg/EdE5jcC) or email us on support AT plenteum.com

#### Thanks
Cryptonote Developers, Bytecoin Developers, Monero Developers, Forknote Project, TurtleCoin Developers and TurtleCoin Community

### Copypasta for license when editing files

Hi Plenteum contributor, thanks for forking and sending back Pull Requests. Extensive docs about contributing are in the works or elsewhere. For now this is the bit we need to get into all the files we touch. Please add it to the top of the files, see src/CryptoNoteConfig.h for an example.

```
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018, The Plenteum Developers
// 
// Please see the included LICENSE file for more information.
```
