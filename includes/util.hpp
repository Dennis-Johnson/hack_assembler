#pragma once
#include <string>
#include <cassert>


namespace Util{
    #define assertm(exp, msg) assert(((void)msg, exp))
    std::string strip(const std::string &inpt);
}