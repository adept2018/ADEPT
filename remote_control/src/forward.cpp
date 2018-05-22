#include "forward.h"

forward::forward(ros::NodeHandle *n): carstate(n)
{
    speed = 0.5;
}

void forward::run(void)
{
    SetSpeed(speed);
    SetWheel(0.5);
    // speed += 0.01;
}

forward::~forward(void)
{
    
}
