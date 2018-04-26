#include "carstate.h"

#pragma once

class leftbackward: public carstate
{
 
protected:

public: 
    leftbackward(void);
    
    std::string run(void);
    
    ~leftbackward(void);
};