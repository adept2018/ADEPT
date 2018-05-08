#include "carstate.h"

carstate::carstate(ros::NodeHandle *n)
{
    _n = n;
    _duty_cycle_pub = n->advertise<std_msgs::Float64>("commands/motor/duty_cycle", 1000);
    _servo_pub = n->advertise<std_msgs::Float64>("commands/servo/position", 1000);
}

carstate::~carstate(void)
{
    
}