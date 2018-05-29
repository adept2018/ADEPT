#include "left.h"

left::left(ros::NodeHandle *n): carstate(n)
{
    
}

void left::run(void)
{
    Ackerman(0, _angle);
}

left::~left(void)
{
    
}