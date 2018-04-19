#include <basic_motion_planner/motion_computer.h>

MotionComputer::MotionComputer(ros::NodeHandle &nh) {
    acquired_scan = false;
    scan_sub = nh.subscribe("/scan", 10, &MotionComputer::scanCallBack, this);
    pose_sub = nh.subscribe("/odom/pose/pose", 10, &MotionComputer::poseCallBack, this);
}

void MotionComputer::scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan) {
    laser_scan = *scan;
    acquired_scan = true;
}

void MotionComputer::poseCallBack(const geometry_msgs::Pose::ConstPtr &pose) {
    if (acquired_scan) {
        scan_queue.push(laser_scan);
        pose_queue.push(*pose);
        acquired_scan = false;
    }
}

bool MotionComputer::computeMotion() {
    while (!scan_queue.empty()) {
        sensor_msgs::LaserScan scan = scan_queue.front();
        geometry_msgs::Pose pose = pose_queue.front();
        scan_queue.pop();
        pose_queue.pop();

        pcl::PointCloud<pcl::PointXY> cloud = laserScanToPointCloud.scanToCloud(scan, pose);

        float x = 0;
        float y = 0;
        std::vector<float> v;

        for (int i = 0; i < cloud.size(); i++) {
            if (cloud.points[i].x != float('inf') && cloud.points[i].y != float('inf')) {
                x += cloud.points[i].x;
                y += cloud.points[i].y;
            }
        }

        v.push_back(-x);
        v.push_back(-y);
    }
    return true;
}
