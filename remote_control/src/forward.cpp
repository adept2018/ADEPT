#include "forward.h"

forward::forward(ros::NodeHandle *n): carstate(n)
{
    
}

void forward::run(void)
{
    SetSpeed(1);
}

forward::~forward(void)
{
    
}
