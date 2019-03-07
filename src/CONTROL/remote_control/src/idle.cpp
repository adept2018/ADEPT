#include "idle.h"

idle::idle(ros::NodeHandle *n): carstate(n)
{
    
}

void idle::run(void)
{
    Ackerman(0, 0);    
}

idle::~idle(void)
{
    
}