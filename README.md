# Installation

## Requirements
The ADEPT software depends on the following components. Scripts are provided to help installing the dependencies

* Ubuntu 16.04
* ROS Kinetic
* CUDA 9
* Stereolabs ZED SDK
* RTIMULib

## Clone the repository
Clone the repository:
```bash
git clone https://github.com/adept2018/ADEPT.git
```

Some external dependencies are included as "git submodules". Do the following from the top ADEPT directory to get that code:
```bash
git submodule init
git submodule update
```

## Install ROS
Ros and other required software can installed by running the following script:

./tools/install_all.sh

This script will run the separate install scripts located in the same directory.

## Setup ROS and build workspace

./tools/setupROS.sh

# Setup IP Addresses
Create a file named "ros_ip_config.sh" with the following content:

```bash
#!/usr/bin/env bash
MY_IP=192.168.0.102
MASTER_IP=192.168.0.106
```
where MY_IP is your local IP address and MASTER_IP is the IP address of the car. The purpose of this file is to keep 
the git repo clean from user-specific content. Do not commit this file!!

The IP adress environment variables can then be set by sourcing:

```bash
source ADEPT/tools/setSource.sh
```

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


# CONTROL

To compile and run the destkop C# remote controll code you need http://www.monogame.net/

To run the car server python code you need https://bottlepy.org/ Use Python 3.


# LOCALIZATION

## Requirements
```bash
sudo apt-get install ros-kinetic-gmapping
```
## How to start SLAM
```bash
roslaunch rplidar_ros viewhectorSlam.launch
```

# PERCEPTION

# MOTIONPLANNING
