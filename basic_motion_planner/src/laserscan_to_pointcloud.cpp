#include <basic_motion_planner/laserscan_to_pointcloud.h>

// 2D rotation matrix R(theta) = [cos(theta) -sin(theta)]
//                               [sin(theta) cos(theta)]

pcl::PointCloud<pcl::PointXY> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan, const geometry_msgs::Pose &pose) {
    pcl::PointXY point;
    pcl::PointCloud<pcl::PointXY> cloud;

    for (int i = 0; i < scan.ranges.size(); i++) {

        float r = scan.ranges[i];
        if (r > 8.0) {  // max range of the laser scanner
            r = 8.0;
        }

        float theta = scan.angle_min + i*scan.angle_increment;  // - pose.orientation.w;

        point.x = r*(cos(theta) - sin(theta));  // - pose.position.x;
        point.y = r*(sin(theta) + cos(theta));  // - pose.position.y;

        cloud.push_back(point);
    }

    return cloud;
}
