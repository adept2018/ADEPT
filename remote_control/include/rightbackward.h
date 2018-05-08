#include "carstate.h"

#pragma once

class rightbackward: public carstate
{
 
protected:

public: 
    rightbackward(ros::NodeHandle *n);
    
    void run(void);
    
    ~rightbackward(void);
};