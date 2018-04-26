#include "carstate.h"

#pragma once

class forward: public carstate
{
 
protected:

public: 
    forward(void);
    
    std::string run(void);
    
    ~forward(void);
};