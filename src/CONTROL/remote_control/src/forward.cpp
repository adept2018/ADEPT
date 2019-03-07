#include "forward.h"

forward::forward(ros::NodeHandle *n): carstate(n)
{

}

void forward::run(void)
{
    Ackerman(_speed, 0);
}

forward::~forward(void)
{
    
}
