#ifndef BASIC_MOTION_PLANNER_H
#define BASIC_MOTION_PLANNER_H

#include <ros/ros.h>
#include <basic_motion_planner/motion_computer.h>

// Publisher:
ros::Publisher pub;

// Subscriber:
ros::Subscriber scan_sub;
ros::Subscriber odom_sub;

#endif //BASIC_MOTION_PLANNER_H
