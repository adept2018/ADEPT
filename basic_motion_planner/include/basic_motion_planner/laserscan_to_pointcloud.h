#ifndef LASERSCAN_TO_POINTCLOUD_H
#define LASERSCAN_TO_POINTCLOUD_H

#include <cmath>

class LaserScanToPointCloud {
private:

public:
    LaserScanToPointCloud() {
    }

    pcl::PointCloud<pcl::PointXY> scanToCloud(const sensor_msgs::LaserScan &scan);
};

#endif //LASERSCAN_TO_POINTCLOUD_H
