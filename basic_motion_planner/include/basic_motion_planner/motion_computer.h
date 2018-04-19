#ifndef MOTION_COMPUTER_H
#define MOTION_COMPUTER_H

#include <cmath>
#include <queue>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <nav_msgs/Odometry.h>

#include <basic_motion_planner/laserscan_to_pointcloud.h>

class MotionComputer {
private:
    bool acquired_scan;

    std::queue<sensor_msgs::LaserScan> scan_queue;
    std::queue<geometry_msgs::PoseWithCovariance> pose_queue;

    void scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan);
    void odomCallBack(const nav_msgs::Odometry::ConstPtr &odom);

public:

};

#endif //MOTION_COMPUTER_H
