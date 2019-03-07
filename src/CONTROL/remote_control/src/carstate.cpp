#include "carstate.h"

#include "ackermann_msgs/AckermannDrive.h"
#include "ackermann_msgs/AckermannDriveStamped.h"

carstate::carstate(ros::NodeHandle *n)
{
    _speed = 1.0;
    _angle = 0.3;
    _n = n;
    // _duty_cycle_pub = n->advertise<std_msgs::Float64>("/commands/motor/duty_cycle", 1000);
    // _servo_pub = n->advertise<std_msgs::Float64>("/commands/servo/position", 1000);
    _ackermann_cmd_mux = n->advertise<ackermann_msgs::AckermannDriveStamped>("/vesc/high_level/ackermann_cmd_mux/input/default", 1000);
}

void carstate::Ackerman(float speed, float angle)
{
    ackermann_msgs::AckermannDriveStamped msg;
    msg.drive.speed = speed;
    msg.drive.steering_angle = angle;
    
    _ackermann_cmd_mux.publish(msg);
}

/*void carstate::SetWheel(float angle)
{
    float servoValue = angle * steeringGain + steeringOffset;
    std_msgs::Float64 msg;
    msg.data = servoValue;
    // msg.data = angle;
    _servo_pub.publish(msg);
    
}

void carstate::SetSpeed(float speed)
{
    // std::cout << "SetSpeed()\n";
    std_msgs::Float64 msg;
    msg.data = speed;
    _duty_cycle_pub.publish(msg);
    
}*/

carstate::~carstate(void)
{
    
}
