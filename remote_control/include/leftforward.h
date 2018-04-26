#include "carstate.h"

#pragma once

class leftforward: public carstate
{
 
protected:

public: 
    leftforward(void);
    
    std::string run(void);
    
    ~leftforward(void);
};