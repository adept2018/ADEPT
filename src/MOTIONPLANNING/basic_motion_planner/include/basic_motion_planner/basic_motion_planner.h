#ifndef BASIC_MOTION_PLANNER_H
#define BASIC_MOTION_PLANNER_H

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <basic_motion_planner/motion_computer.h>
#include <geometry_msgs/PoseStamped.h>
#include <ackermann_msgs/AckermannDriveStamped.h>

// Publishers:
ros::Publisher pubCloudVisible;
ros::Publisher pubCloudInvisible;
ros::Publisher pubPose;
ros::Publisher pubDirection;
ros::Publisher pubAck;

#endif //BASIC_MOTION_PLANNER_H
