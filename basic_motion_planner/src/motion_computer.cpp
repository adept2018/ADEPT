#include <basic_motion_planner/motion_computer.h>

MotionComputer::MotionComputer(ros::NodeHandle &nh) {
    acquired_scan = false;
    scan_sub = nh.subscribe("/scan", 10, &MotionComputer::scanCallBack, this);
    odom_sub = nh.subscribe("/odom", 10, &MotionComputer::odomCallBack, this);
}

void MotionComputer::scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan) {
    laser_scan = *scan;
    acquired_scan = true;
}

void MotionComputer::odomCallBack(const nav_msgs::Odometry::ConstPtr &odom) {
    if (acquired_scan) {
        scan_queue.push(laser_scan);
        odom_queue.push(*odom);
        acquired_scan = false;
    }
}

bool MotionComputer::computeMotion() {
    //std::cerr << scan_queue.size() << std::endl;
    while (!scan_queue.empty()) {
        sensor_msgs::LaserScan scan = scan_queue.front();
        nav_msgs::Odometry odom = odom_queue.front();
        scan_queue.pop();
        odom_queue.pop();

        v.clear();
        cloud.clear();

        cloud = laserScanToPointCloud.scanToCloud(scan, odom.pose.pose);
        float x = 0;
        float y = 0;
        float z = 0;

        // the simple motion planner
        for (int i = 0; i < cloud.size(); i++) {
            x += cloud.points[i].x;
            y += cloud.points[i].y;
        }
        v.push_back(-x);
        v.push_back(-y);
        v.push_back(z);
    }
    return true;
}
