#include <basic_motion_planner/laserscan_to_pointcloud.h>

pcl::PointCloud<pcl::PointXYZ> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan) {
    pcl::PointXYZ point;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    for (int i = 0; i < scan.ranges.size(); i++) {

        float r = scan.ranges[i];

        if (r > 2.0 || r < 0.3) {
            continue;
        }

        // Offset of the lidar is 90 degrees
        float offset = 1.5708;
        float theta = scan.angle_min + i * scan.angle_increment + offset;

        float angle_range = 0.5;
        if (theta < -angle_range || theta > angle_range) {
            continue;
        }

        point.x = r * cos(theta);
        point.y = r * sin(theta);
        point.z = 0;

        cloud.push_back(point);
    }

    return cloud;
}
