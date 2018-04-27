#!/bin/bash

echo 'Upgrading Ubuntu'
sudo apt upgrade

WORKSPACE=~/ADEPT_ws

echo 'Installing ROS..'

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt-get update
sudo apt-get install -y ros-kinetic-desktop-full
sudo rosdep init
rosdep update
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt-get install -y python-rosinstall python-rosinstall-generator python-wstool build-essential

echo 'Cloning git repos..'
# Get dir where this script is located
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR
# Run setup script that clones all repos
./setupAdept.sh

echo 'Building ros nodes..'
cd $WORKSPACE
rosdep install --from-paths src --ignore-src -r -y
rosdep update
catkin_make
source devel/setup.bash


