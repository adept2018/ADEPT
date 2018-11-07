#include "rightforward.h"

rightforward::rightforward(ros::NodeHandle *n): carstate(n)
{
    
}

void rightforward::run(void)
{
    Ackerman(_speed, -_angle);
}

rightforward::~rightforward(void)
{
    
}