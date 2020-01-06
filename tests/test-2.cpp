#include <iostream>
#include <string>
#include <stdexcept>
#include "..\CTest\ctest.h"

int test()
{
    std::cout << "Calling function" << std::endl;
    //throw std::domain_error("Some test error");
    return 0;
}

int main(int argc, char** argv)
{
    ct::is_equal(5, 5, "Testing equality");
    ct::is_equal(5, 6, "Testing inequality");
    ct::is_equal("Andrei", "Andrei", "Testing strings");
    ct::is_equal("Andrei", "andrei", "Testing strings inequality");
    size_t i, j;
    i = j = 10;
    ct::is_equal(i, j, "Testing longs");
    ct::is_exc(test, "Testing function");
    return 0;
}