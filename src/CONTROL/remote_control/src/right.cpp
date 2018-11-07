#include "right.h"

right::right(ros::NodeHandle *n): carstate(n)
{
    
}

void right::run(void)
{
    Ackerman(0, -_angle);
}

right::~right(void)
{
    
}