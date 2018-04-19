#ifndef LASERSCAN_TO_POINTCLOUD_H
#define LASERSCAN_TO_POINTCLOUD_H

#include <cmath>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseWithCovariance.h>

class LaserScanToPointCloud {
private:

public:
    LaserScanToPointCloud() {
    }

    pcl::PointCloud<pcl::PointXY> scanToCloud(const sensor_msgs::LaserScan &scan, const geometry_msgs::PoseWithCovariance &pose);
};

#endif //LASERSCAN_TO_POINTCLOUD_H
