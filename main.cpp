#include "TestSuite/Suite.h"
#include "PostOfficeTest.hpp"
#include "ParcelTest.hpp"

int main (int argc, const char * argv[])
{
    TestSuite::Suite tests("Test semestralni zkousky C++");
    tests.addTest(new ParcelTest);
    tests.addTest(new PostOfficeTest);

    tests.run();
    tests.report();
    
    return 0;
}

