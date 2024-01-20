#include "driver.h"
#include <iostream>
using namespace std;

int main()
{
    HashMapDriver driver;
    driver.setUpFiles();
    driver.readAndProcess();
    driver.testDictionary();

    return 0;
} // main
