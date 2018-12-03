#!/usr/bin/env bash

echo 'Installing Stereolabs ZED SDK'
wget https://download.stereolabs.com/zedsdk/2.7/ubuntu16_cuda9
chmod +x ubuntu16_cuda9
./ubuntu16_cuda9
rm ubuntu16_cuda9
