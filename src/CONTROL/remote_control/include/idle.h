#include "carstate.h"

#pragma once

class idle: public carstate
{
 
protected:

public: 
    idle(ros::NodeHandle *n);
    
    void run(void);
    
    ~idle(void);
};