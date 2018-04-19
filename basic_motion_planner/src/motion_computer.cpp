#include <basic_motion_planner/motion_computer.h>

MotionComputer::MotionComputer() {
    acquired_scan = false;
}

void MotionComputer::scanCallBack(const sensor_msgs::LaserScan::ConstPtr &scan) {
    acquired_scan = true;
}

void MotionComputer::odomCallBack(const nav_msgs::Odometry::ConstPtr &odom) {
    if(acquired_scan) {
        scan_queue.push(*scan);
        pose_queue.push(*odom::pose);
        acquired_scan = false;
    }
}
