#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>
#include "..\CTest\ctest.h"

int test()
{
    std::cout << "Calling function" << std::endl;
    //throw std::domain_error("Some test error");
    return 0;
}

void hello(std::string hello)
{
    std::cout << "Hello, " + hello << std::endl;
}

int callb(std::function<void()> cb)
{
    cb();
    return 0;
}

int main(int argc, char** argv)
{
    ct::assert_equal(5, 5, "Testing equality");
    ct::assert_equal(5, 6, "Testing inequality");
    ct::assert_equal("Andrei", "Andrei", "Testing strings");
    ct::assert_equal("Andrei", "andrei", "Testing strings inequality");
    size_t i, j;
    i = j = 10;
    ct::assert_equal(i, j, "Testing longs");
    ct::assert_exc(ct::func(hello, "Bond"), "Testing function");
    ct::assert_true(1 == 2, "Testing bool.");
    return 0;
}