#include "carstate.h"

#pragma once

class right: public carstate
{
 
protected:

public: 
    right(ros::NodeHandle *n);
    
    void run(void);
    
    ~right(void);
};