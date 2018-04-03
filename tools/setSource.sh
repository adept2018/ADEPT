#!bin/sh

func () {
	local MY_IP=10.0.79.101
	local MASTER_IP=10.0.75.208

	export ROS_MASTER_URI=http://$MASTER_IP:11311
	export ROS_HOSTNAME=$MY_IP
	export ROS_IP=$MY_IP
}

func
source devel/setup.bash

