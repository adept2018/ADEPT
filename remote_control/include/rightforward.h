#include "carstate.h"

#pragma once

class rightforward: public carstate
{
 
protected:

public: 
    rightforward(ros::NodeHandle *n);
    
    void run(void);
    
    ~rightforward(void);
};