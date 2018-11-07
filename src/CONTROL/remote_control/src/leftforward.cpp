#include "leftforward.h"

leftforward::leftforward(ros::NodeHandle *n): carstate(n)
{
    
}

void leftforward::run(void)
{
    Ackerman(_speed, _angle);
}

leftforward::~leftforward(void)
{
    
}