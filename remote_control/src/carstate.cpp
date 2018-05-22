#include "carstate.h"

carstate::carstate(ros::NodeHandle *n)
{
    _n = n;
    _duty_cycle_pub = n->advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
    _servo_pub = n->advertise<std_msgs::Float64>("commands/servo/position", 1000);
    
    
}

void carstate::SetWheel(float angle)
{
    float servoValue = angle * steeringGain + steeringOffset;
    std_msgs::Float64 msg;
    // msg.data = servoValue;
    msg.data = angle;
    _servo_pub.publish(msg);
    
}

void carstate::SetSpeed(float speed)
{
    // std::cout << "SetSpeed()\n";
    std_msgs::Float64 msg;
    msg.data = speed;
    _duty_cycle_pub.publish(msg);
    
}

carstate::~carstate(void)
{
    
}
