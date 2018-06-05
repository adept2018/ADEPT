#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "carstate.h"

#pragma once

class avoid: public carstate
{
 
protected:

    // ros::Subscriber sub;

public: 
    avoid(ros::NodeHandle *n);
    
    void run(void);
    
    ~avoid(void);
};

