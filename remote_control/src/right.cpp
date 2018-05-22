#include "right.h"

right::right(ros::NodeHandle *n): carstate(n)
{
    
}

void right::run(void)
{
    SetWheel(45); // 45 degrees right I hope.
}

right::~right(void)
{
    
}