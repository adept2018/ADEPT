#include "backward.h"

backward::backward(ros::NodeHandle *n): carstate(n)
{
    
}

void backward::run(void)
{
    Ackerman(-_speed, 0);    
}

backward::~backward(void)
{
    
}