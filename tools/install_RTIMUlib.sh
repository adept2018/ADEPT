#!/usr/bin/env bash

# Get location of this script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR

mkdir tmp && cd tmp
git clone https://github.com/richardstechnotes/RTIMULib2.git
cd RTIMULib2/Linux
mkdir build && cd build
cmake .. && make && sudo make install
cd $DIR
rm -rf tmp