#include "driver.h"

int main()
{
    HashMapDriver driver;

    driver.setUpFiles();
    driver.readAndProcess();
    driver.testDictionary();

    return 0;
} // main
