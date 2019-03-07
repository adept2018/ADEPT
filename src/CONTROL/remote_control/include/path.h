#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "carstate.h"

#pragma once

class path: public carstate
{
 
protected:

    // ros::Subscriber sub;

public: 
    path(ros::NodeHandle *n);
    
    void run(void);
    
    ~path(void);
};

