#include <basic_motion_planner/laserscan_to_pointcloud.h>

// 2D rotation matrix R(theta) = [cos(theta) -sin(theta)]
//                               [sin(theta) cos(theta)]

pcl::PointCloud<pcl::PointXYZ> LaserScanToPointCloud::scanToCloud(const sensor_msgs::LaserScan &scan) {
    pcl::PointXYZ point;
    pcl::PointCloud<pcl::PointXYZ> cloud;

    // std::cout<<"min_angle="<<scan.angle_min<<" max_angle="<<scan.angle_max<<" angle_increment="<<scan.angle_increment<<std::endl;
    // std::cout<<"min_range="<<scan.range_min<<" max_range="<<scan.range_max<<std::endl;

    for (int i = 0; i < scan.ranges.size(); i++) {

        float r = scan.ranges[i];
        std::cout<<"i="<<i<<" range="<<r<<std::endl;

        if (r > 2.0 || r < 0.3) {
            continue;
        }

        float theta = scan.angle_min + i * scan.angle_increment - 1.5708;

        if (theta < -0.4014 || theta > 0.4014) {
            continue;
        }

        point.x = r * (cos(theta) - sin(theta));
        point.y = r * (sin(theta) + cos(theta));
        point.z = 0;

        cloud.push_back(point);
    }

    return cloud;
}
