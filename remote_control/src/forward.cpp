#include "forward.h"

forward::forward(ros::NodeHandle *n): carstate(n)
{
    
}

void forward::run(void)
{
    SetSpeed(0.1);
    SetWheel(3.14/4);
}

forward::~forward(void)
{
    
}
