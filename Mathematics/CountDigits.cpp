#include <iostream>

int GetNoOfDigits(int n)
{
    int noOfInt = 0;
    while (n > 0)
    {
        n = n / 10;
        noOfInt++;
    }
    return noOfInt;
}

int CountDigits()
{
    int n = 123456789;
    std::cout << "No of integers are " << GetNoOfDigits(n) << std::endl;
    return 0;
}

