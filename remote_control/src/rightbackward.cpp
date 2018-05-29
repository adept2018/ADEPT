#include "rightbackward.h"

rightbackward::rightbackward(ros::NodeHandle *n): carstate(n)
{
    
}

void rightbackward::run(void)
{
    Ackerman(-_speed, -_angle);    
}

rightbackward::~rightbackward(void)
{
    
}