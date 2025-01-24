#include <iostream>

int GetFactorial(int n)
{
    if (n == 1)
        return 1;

    return n * GetFactorial(n-1);
}

int Factorial()
{
    int n = 6;
    std::cout << "The factorial no is " << GetFactorial(n) << std::endl;
    return 0;
}

