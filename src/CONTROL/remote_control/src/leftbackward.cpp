#include "leftbackward.h"

leftbackward::leftbackward(ros::NodeHandle *n): carstate(n)
{
    
}

void leftbackward::run(void)
{
    Ackerman(-_speed, _angle);
}

leftbackward::~leftbackward(void)
{
    
}