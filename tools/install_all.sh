#!/usr/bin/env bash

# Get location of this script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR

./installROS.sh
./install_CUDA.sh
./install_ZEDSDK.sh
./install_RTIMUlib.sh
