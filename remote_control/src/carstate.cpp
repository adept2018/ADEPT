#include "carstate.h"

carstate::carstate(ros::NodeHandle *n)
{
    _n = n;
    _duty_cycle_pub = n->advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
    _servo_pub = n->advertise<std_msgs::Float64>("commands/servo/position", 1000);
}


void carstate::SetWheel(double angle)
{
    std_msgs::Float64 msg;
    msg.data = static_cast<float>(angle);
    _servo_pub.publish(msg);
    
}

void carstate::SetSpeed(double speed)
{
    std_msgs::Float64 msg;
    msg.data = static_cast<float>(speed);
    _duty_cycle_pub.publish(msg);
    
}

carstate::~carstate(void)
{
    
}
