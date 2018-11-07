#include "carstate.h"

#pragma once

class leftbackward: public carstate
{
 
protected:

public: 
    leftbackward(ros::NodeHandle *n);
    
    void run(void);
    
    ~leftbackward(void);
};