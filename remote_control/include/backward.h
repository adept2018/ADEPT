#include "carstate.h"

#pragma once

class backward: public carstate
{
 
protected:

public: 
    backward(void);
    
    std::string run(void);
    
    ~backward(void);
};