#include <basic_motion_planner/motion_computer.h>

MotionComputer::MotionComputer(ros::NodeHandle &nh) {
    scan_sub = nh.subscribe("/scan", 10, &MotionComputer::scanCallBack, this);
}

void MotionComputer::scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan) {
    laser_scan = *scan;
    scan_queue.push(laser_scan);
}

bool MotionComputer::computeMotion() {
    while (!scan_queue.empty()) {
        sensor_msgs::LaserScan scan = scan_queue.front();
        scan_queue.pop();

        v.clear();
        cloud.clear();

        cloud = laserScanToPointCloud.scanToCloud(scan);
        float x = 0;
        float y = 0;
        float z = 0;

        int numberOfPoints = cloud.size();

        // the simple motion planner
        for (int i = 0; i < numberOfPoints; i++) {
            x += 1 / cloud.points[i].x;
            y += 1 / cloud.points[i].y;
        }

        float length = sqrt(x * x + y * y);
        x = x / length;
        y = y / length;

        v.push_back(-x);
        v.push_back(-y);
        v.push_back(z);
    }
    return true;
}
