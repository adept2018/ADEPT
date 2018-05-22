#include "right.h"

right::right(ros::NodeHandle *n): carstate(n)
{
    
}

void right::run(void)
{
    SetWheel(3.14/4);
}

right::~right(void)
{
    
}