#include "carstate.h"

#pragma once

class rightbackward: public carstate
{
 
protected:

public: 
    rightbackward(void);
    
    std::string run(void);
    
    ~rightbackward(void);
};