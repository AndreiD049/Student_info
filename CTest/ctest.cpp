#include <iostream>
#include "ctest.h"


namespace ct
{
    bool assert(bool test, std::string test_name)
    {
        if (test)
        {
            std::cout << "Success: " + test_name << std::endl;
            return true;
        }
        else
        {
            std::cout << "Failure: " + test_name << std::endl;
            return false;
        }
    }
}
