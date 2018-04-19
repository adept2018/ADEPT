#include <basic_motion_planner/laserscan_to_pointcloud.h>

// 2D rotation matrix R(theta) = [cos(theta) -sin(theta); sin(theta) cos(theta)]

pcl::PointCloud<pcl::PointXY> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan) {

    // float angle_min = scan.angle_min;
    // float angle_max = scan.angle_max;
    // float angle_incr = scan.angle_increment;

    pcl::PointXy point;
    pcl::PointCloud cloud;

    for (int i = 0; i < scan.ranges.size(); i++) {

        float r = scan.ranges[i];

        //point.x = 
        //point.y =

    }

    return cloud;
}
