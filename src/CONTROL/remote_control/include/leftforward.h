#include "carstate.h"

#pragma once

class leftforward: public carstate
{
 
protected:

public: 
    leftforward(ros::NodeHandle *n);
    
    void run(void);
    
    ~leftforward(void);
};