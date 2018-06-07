#include <basic_motion_planner/motion_computer.h>

#define PI 3.14159265

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
        visibleCloud.clear();
        invisibleCloud.clear();

        visibleCloud = laserScanToPointCloud.scanToCloud(scan, true);
        invisibleCloud = laserScanToPointCloud.scanToCloud(scan, false);

        int numberOfPoints = visibleCloud.size();

        if (numberOfPoints > 0) {
            float theta = 0;

            // Sum all angles
            for (int i = 0; i < numberOfPoints; i++) {
                float x = visibleCloud.points[i].x;
                float y = visibleCloud.points[i].y;
                theta += atan(y / x);
            }

            // Dived angle by number of points
            float theta_w = theta / numberOfPoints;

            // Offset to turn away from obstacle
            float offset = 0.52;

            // Decide which way to turn away from obstacle
            if (theta_w < 0) {
                theta_w += offset;
            } else {
                theta_w += -offset;
            }

            v.push_back(cos(theta_w));
            v.push_back(sin(theta_w));
            v.push_back(theta_w);
        }
    }
    return true;
}
