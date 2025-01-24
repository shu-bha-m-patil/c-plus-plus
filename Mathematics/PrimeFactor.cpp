#include <iostream>

bool IsPrime(int a)
{
    if (a == 1)
        return false;

    if (a % 2 == 0 || a % 3 == 0)
        return true;

    for (size_t i = 5; i * i < a; i = i + 6)
    {
        if ((a % i) == 0 || (a % (i + 2)) == 0)
            return false;
    }

    return true;
}

void PrintPrimeNos(int a)
{
    while ((a % 2) == 0)
    {
        std::cout << 2 << ", ";
        a = a / 2;
    }
    
    while ((a % 3) == 0)
    {
        std::cout << 3 << ", ";
        a = a / 3;
    }

    for (size_t i = 5; i <= a; i = i + 6)
    {
        while ((a % i) == 0)
        {
            std::cout << i << ", ";
            a = a / i;
        }

        while ((a % (i + 2)) == 0)
        {
            std::cout << i + 2 << ", ";
            a = a / (i + 2);
        }
    }
}

int main()
{
    int a = 0;
    std::cout << "Enter the no : ";
    std::cin >> a;
    std::cout << "The prime nos are : ";
    PrintPrimeNos(a);
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter some values ";
    std::cin >> temp;

    return 0;
}

/*

Greates common divisor | Highest comman factor

a & b

Let n is the greatest common divisor
a = nx 
b = ny
    x and y HCF is 1;

a - b = n (x - y);

*/