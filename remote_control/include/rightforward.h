#include "carstate.h"

#pragma once

class rightforward: public carstate
{
 
protected:

public: 
    rightforward(void);
    
    std::string run(void);
    
    ~rightforward(void);
};