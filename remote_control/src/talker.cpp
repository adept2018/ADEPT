#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <sstream>4



/*

How to start it.
roslaunch vesc_driver vesc_driver_node.launch
roslaunch vesc_driver remote_control.launch

*/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");


  ros::NodeHandle n;

  ros::Publisher duty_cycle_pub = n.advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
  ros::Publisher servo_pub = n.advertise<std_msgs::Float64>("commands/servo/position", 1000);
  
  //ros::Publisher current_pub_ = n.advertise<std_msgs::Float64>("commands/motor/current", 1000);
  //ros::Publisher brake_pub_ = n.advertise<std_msgs::Float64>("commands/motor/brake", 1000);
  //ros::Publisher speed_pub_ = n.advertise<std_msgs::Float64>("commands/motor/speed", 1000);
  //ros::Publisher position_pub_ = n.advertise<std_msgs::Float64>("commands/motor/position", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  std_msgs::Float64 msg;
  while (ros::ok())
  {

    msg.data = static_cast<float>(count*0.0001);

    ROS_INFO("%s", msg.data);

    // duty_cycle_pub.publish(msg);
    servo_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
