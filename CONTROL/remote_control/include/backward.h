#include "carstate.h"

#pragma once

class backward: public carstate
{
 
protected:

public: 
    backward(ros::NodeHandle *n);
    
    void run(void);
    
    ~backward(void);
};