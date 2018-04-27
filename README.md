# ADEPT

## Requirements
* Ubuntu 16.04
* ROS Kinetic
* Git
* ..?


## Getting started
To download all the repo's and setup the catkin workspace included in the ADEPT repo run the following script.
    ./tools/setupAdept.sh
This will setup the ADEPT project in the following folder ~/ADEPT_ws/

## Quick start guide
To install all dependencies, download all the repo's, and build the code on a fresh install of Ubuntu run the following script. 

./tools/installAll.sh

## Install ROS
Ros can be installed separately by running script

./tools/installRos.sh

## Install ubuntu on usb flash drive
Before getting started, you need these items.

* 8GB+ USB Drive.
* Ubuntu Live CD/DVD/USB. In the case below, we create a bootable Ubuntu Live USB from an .iso image.
* Computer with an operating system installed.

Download an ubuntu image version 16.04 LTS from ubuntu.com

Plug in an usb drive that you want to make an Ubuntu Live USB. It needs to be atleast 4 Gb.

On ubuntu: Use Startup disc creator, choose the iso ubuntu image and select the usb drive and start writing the image.
On windows: Use win32 disk imager.

After creating the Ubuntu Live USB, plug in the other 8Gb+ USB drive
Reboot computer and boot from Ubuntu live usb drive. How to boot from and USB drive may differ for different computer.

Choose install ubuntu.

Choose erase disk and install.

Choose the 8gb+ USB drive as disk to install ubuntu on.
