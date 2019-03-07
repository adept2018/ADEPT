#!/usr/bin/env bash

func () {
	# Get dir where this script is located
	DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

	if [ -e $DIR/ros_ip_config.sh ] 
	then
		source $DIR/ros_ip_config.sh 
	else 
		echo "setSource.sh ERROR: You need to create file tools/ros_ip_config.sh containing IP Adress configuration. See README.md" 
	fi

	export ROS_MASTER_URI=http://$MASTER_IP:11311
	export ROS_HOSTNAME=$MY_IP
	export ROS_IP=$MY_IP
}

func
