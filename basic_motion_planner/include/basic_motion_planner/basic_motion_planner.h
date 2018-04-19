#ifndef BASIC_MOTION_PLANNER_H
#define BASIC_MOTION_PLANNER_H

#include <ros/ros.h>

// PCL specific includes:
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <basic_motion_planner/motion_computer.h>

// Publisher:
ros::Publisher pub;

// Subscriber:
ros::Subscriber scan_sub;
ros::Subscriber odom_sub;

#endif //BASIC_MOTION_PLANNER_H
