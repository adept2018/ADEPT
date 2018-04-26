#include <vector>
#include <string>

#pragma once

class carstate
{
protected:
    static double speed;
    static double angle;
    // static std:vector<Vector2D> path;
    
public:
    carstate(void);
    
    virtual std::string run(void) = 0;
    
    // void Target(Vector2D vector);
    
    virtual ~carstate(void);
};