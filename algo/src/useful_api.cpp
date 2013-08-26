#include "algo.hpp"
#include <sstream>

// Convert an integer value to string
std::string intToStr(int val) 
{
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

// minimum of three integers
int minOfThree(int a, int b, int c) 
{
    if (a<b) {
        if (c<a) return c; 
        else     return a;    
    } else {
        if (c<b) return c;
        else     return b;
    }
}

