#!/usr/bin/env bash

echo 'Upgrading Ubuntu'
sudo apt upgrade #TODO: test to run "sudo c_rehash /etc/ssl/certs" instead 

# Get dir where this script is located
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKSPACE=$(dirname $DIR)

source /opt/ros/kinetic/setup.bash

echo 'Building ros nodes..'
cd $WORKSPACE
rosdep install --from-paths src --ignore-src -r -y
rosdep update
catkin_make

echo "source $WORKSPACE/tools/initWorkspace.sh" >> ~/.bashrc

source $WORKSPACE/tools/initWorkspace.sh
