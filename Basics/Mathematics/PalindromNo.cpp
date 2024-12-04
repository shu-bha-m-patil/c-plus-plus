#include <iostream>

bool IsPalindromNo(int n)
{
    int temp = n;
    int newNO = 0;
    while (temp > 0)
    {
        int lastDigit = temp % 10;
        temp = temp / 10;
        newNO = newNO * 10 + lastDigit;
    }
    if (n == newNO)
        return true;
    return false;
}

int PalindromNo()
{
    int n = 12261;
    if (IsPalindromNo(n))
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    return 0;
}

