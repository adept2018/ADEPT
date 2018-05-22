#ifndef BASIC_MOTION_PLANNER_H
#define BASIC_MOTION_PLANNER_H

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <basic_motion_planner/motion_computer.h>
#include <geometry_msgs/PoseStamped.h>

// Publishers:
ros::Publisher pubCloud;
ros::Publisher pubPose;

#endif //BASIC_MOTION_PLANNER_H
