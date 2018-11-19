#!/usr/bin/env bash

echo 'Installing ROS kinetic'

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt-get update
sudo apt-get install -y ros-kinetic-desktop-full
sudo rosdep init
rosdep update
sudo apt-get install -y python-rosinstall python-rosinstall-generator python-wstool build-essential

echo 'Installing Nvidia CUDA'
mkdir tmp_cuda_install
cd tmp_cuda_install
wget https://developer.nvidia.com/compute/cuda/9.0/Prod/local_installers/cuda_9.0.176_384.81_linux-run
chmod +x cuda_9.0.176_384.81_linux-run
# We only want to install CUDA toolkit, no graphics driver so extract contents, then install
./cuda_9.0.176_384.81_linux-run --extract=$PWD
sudo ./cuda-linux.9.0.176-22781540.run
cd ..
rm -rf tmp_cuda_install

echo 'Installing Stereolabs ZED SDK'
wget https://download.stereolabs.com/zedsdk/2.7/ubuntu16_cuda9
chmod +x ubuntu16_cuda9
./ubuntu16_cuda9
rm ubuntu16_cuda9
