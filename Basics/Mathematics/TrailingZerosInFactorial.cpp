#include <iostream>

int GetFact(int n)
{
    if (n == 1)
        return 1;

    int fact = n * GetFact(n - 1);
    return fact;
}

int GetZerosInFactorial(int n)
{
    int noOfZeros = n / 5;
    return noOfZeros;
}

int main()
{
    int n = 11;
    std::cout << "The no of zeros " << GetZerosInFactorial(n) << std::endl;
    return 0;
}

