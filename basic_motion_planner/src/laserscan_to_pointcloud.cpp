#include <basic_motion_planner/laserscan_to_pointcloud.h>

bool LaserScanToPointCloud::filter(float range, float angle) {
  float max_range = 2.0;
  float min_range = 0.3;

  if (range > max_range || range < min_range) {
      return false;
  }

  float angle_range = 0.5;
  if (angle < -angle_range || angle > angle_range) {
      return false;
  }
  
  return true;
}

pcl::PointCloud<pcl::PointXYZ> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan, bool insideFilter) {
    pcl::PointXYZ point;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    for (int i = 0; i < scan.ranges.size(); ++i) {

        float r = scan.ranges[i];

        // Offset of the lidar is 90 degrees
        float pi = atan(1)*4;
        float offset = pi/2;
        float theta = scan.angle_min + i * scan.angle_increment + offset;

        if (filter(r, theta) == insideFilter) {
          point.x = r * cos(theta);
          point.y = r * sin(theta);
          point.z = 0;

          cloud.push_back(point);
        }
    }

    return cloud;
}
