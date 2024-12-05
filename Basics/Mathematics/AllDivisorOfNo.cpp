#include <iostream>

bool DivisorOfNo(int a)
{
    size_t i = 1;
    for (i; i * i <= a; i++)
    {
        if ((a % i) == 0)
        {
            std::cout << i << ", ";
        }
    }

    for (i; i >= 1; i--)
    {
        if ((a % i) == 0)
        {
            if (a / i != i)
                std::cout << a / i << ", ";
        }
    }

    return true;
}

int main()
{
    int a = 0;
    std::cout << "Enter the no : ";
    std::cin >> a;
    std::cout << "The divisor of no are : ";
    DivisorOfNo(a);
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