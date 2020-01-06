#include <iostream>
#include <string>


namespace ct
{
    bool assert(bool, std::string);

    template<class T>
    bool is_equal(T actual, T expected, std::string message)
    {
        return assert(actual == expected, message);
    }

    template<class T>
    bool is_exc(T actual(), std::string message)
    {
        try
        {
            actual();
            return assert(true, message);
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return assert(false, message + "[" + e.what() + "]");
        }
    }
}