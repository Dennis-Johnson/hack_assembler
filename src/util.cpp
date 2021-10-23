/*
utils.cpp

Some Utilities.
*/

#include "../includes/util.hpp"
#include <string>

namespace Util {
    std::string strip(const std::string &inpt)
    {
        auto start_it = inpt.begin();
        auto end_it = inpt.rbegin();
        while (std::isspace(*start_it))
            ++start_it;
        while (std::isspace(*end_it))
            ++end_it;

        // Ensure iterators don't cross.
        if (std::distance(start_it, end_it.base()) > 0)
            return std::string(start_it, end_it.base());

        return "";
    }
};