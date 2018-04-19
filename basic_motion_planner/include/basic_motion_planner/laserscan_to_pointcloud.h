#ifndef LASERSCAN_TO_POINTCLOUD_H
#define LASERSCAN_TO_POINTCLOUD_H

#include <cmath>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Pose.h>

// PCL specific includes:
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class LaserScanToPointCloud {
private:

public:
    LaserScanToPointCloud() {
    }

    pcl::PointCloud<pcl::PointXY> scanToCloud(const sensor_msgs::LaserScan &scan, const geometry_msgs::Pose &pose);
};

#endif //LASERSCAN_TO_POINTCLOUD_H
