#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "carstate.h"

#pragma once

class forward: public carstate
{
 
protected:

public: 
    forward(ros::NodeHandle *n);
    
    void run(void);
    
    ~forward(void);
};