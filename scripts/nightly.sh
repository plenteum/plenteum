#!/usr/bin/env bash

# nightly.sh - pull a copy of plenteum-development 
# and put it inside a timestamped folder.
# rock made this

sourcefolder=~/Source/plenteum-dev-build-$(date +%F)

mkdir ~/Source
mkdir ~/Binaries
echo -e "\n MOVING TO ~/Source"
cd ~/Source/
ls -al

echo -e "\n CLONING Plenteum in $sourcefolder"
git clone -b development https://github.com/plenteum/plenteum $sourcefolder
cd $sourcefolder
mkdir -p $sourcefolder/build && cd $sourcefolder/build
ls -al

echo -e "\n BUILDING Plenteum"
cmake .. && make -j8 # remove -j8 for single core
cd src
ls -al

echo -e "\n\n COMPRESSING BINARIES"
zip plenteum-dev-bin-$(date +%F)-linux.zip miner poolwallet simplewallet Plenteumd walletd
mv *.zip ~/Binaries/
cd ~/Binaries
ls -al

echo -e "\n COMPLETE!"
