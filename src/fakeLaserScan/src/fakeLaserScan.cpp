#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

static const double angle_min= -3.14*0.9, angle_max=3.14*0.9;

int main(int argc, char** argv){
  ros::init(argc, argv, "fake_laser_scan_publisher");

  ros::NodeHandle n;
  ros::Publisher scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 50);

  unsigned int num_readings = 100;
  double laser_frequency = 1000;
  double ranges[num_readings];
  double intensities[num_readings];

  int count = 0;
  ros::Rate r(5.0);
  while(n.ok()){
    //generate some fake data for our laser scan
    for(unsigned int i = 0; i < num_readings; ++i){
      ranges[i] = 1.0 + (count % 5)/10.0;
      intensities[i] = 100 + count % 10; 
    }
    ros::Time scan_time = ros::Time::now();

    //populate the LaserScan message
    sensor_msgs::LaserScan scan;
    scan.header.stamp = scan_time;
    scan.header.frame_id = "laser";
    scan.angle_min = angle_min;
    scan.angle_max = angle_max;
    scan.angle_increment = (angle_max - angle_min) / (num_readings-1);
    scan.time_increment = (1 / laser_frequency) / (num_readings-1);
    scan.range_min = 0.0;
    scan.range_max = 100.0;

    scan.scan_time = (1 / laser_frequency);

    scan.ranges.resize(num_readings);
    scan.intensities.resize(num_readings);
    for(unsigned int i = 0; i < num_readings; ++i){
      scan.ranges[i] = ranges[i];
      scan.intensities[i] = intensities[i];
    }

    scan_pub.publish(scan);
    ++count;
    r.sleep();
  }
}
