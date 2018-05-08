#include "carstate.h"

#pragma once

class left: public carstate
{
 
protected:

public: 
    left(ros::NodeHandle *n);
    
    void run(void);
    
    ~left(void);
};