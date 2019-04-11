#!/usr/bin/env bash

echo 'Installing Nvidia CUDA'
mkdir tmp_cuda_install
cd tmp_cuda_install
wget https://developer.nvidia.com/compute/cuda/9.0/Prod/local_installers/cuda_9.0.176_384.81_linux-run
chmod +x cuda_9.0.176_384.81_linux-run
# We only want to install CUDA toolkit, no graphics driver so extract contents, then install
./cuda_9.0.176_384.81_linux-run --extract=$PWD
sudo ./cuda-linux.9.0.176-22781540.run --silent
cd ..
rm -rf tmp_cuda_install