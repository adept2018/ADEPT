#include <vector>
#include <string>
#include "ros/ros.h"
#include "std_msgs/Float64.h"

#pragma once

class carstate
{
protected:
    
    // MAYBE: make thise singleton... (probaly not)
    ros::Publisher _duty_cycle_pub;
    ros::Publisher _servo_pub;
    ros::NodeHandle *_n;
    
public:
    carstate(ros::NodeHandle *n);
    
    virtual void run(void) = 0;
    
    void SetWheel(double angle);
    void SetSpeed(double speed);
    
    virtual ~carstate(void);
};