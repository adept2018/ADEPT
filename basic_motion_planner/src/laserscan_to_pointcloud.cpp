#include <basic_motion_planner/laserscan_to_pointcloud.h>

// 2D rotation matrix R(theta) = [cos(theta) -sin(theta)]
//                               [sin(theta) cos(theta)]

pcl::PointCloud<pcl::PointXYZ> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan) {
    pcl::PointXYZ point;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    for (int i = 0; i < scan.ranges.size(); i++) {

        float r = scan.ranges[i];

        if (r > 2.0 || r < 0.3) {  // max range of the laser scanner
            continue;
        }

        float theta = scan.angle_min + i * scan.angle_increment;

        point.x = r * (cos(theta) - sin(theta));
        point.y = r * (sin(theta) + cos(theta));
        point.z = 0;

        cloud.push_back(point);
    }

    return cloud;
}
