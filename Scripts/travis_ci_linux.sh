#!/bin/sh
set -e

export NUM_JOBS=1

sudo apt-get update
sudo apt-get install libc++6

mkdir Bin
cd Bin
cmake ..
make
./bin/GoonRenderer