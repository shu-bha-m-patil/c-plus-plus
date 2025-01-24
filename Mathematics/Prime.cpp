#include <iostream>

bool IsPrime(int a)
{
    if (a == 1)
        return false;

    if ((a % 2) == 0 || (a % 3) == 0)
        return true;

    for (int i = 5; i * i < a; i = i + 5)
    {
        if ((a % i) == 0 || (a % (i + 2)) == 0)
            return false;
    }

    return true;
}

int main()
{
    int a = 0;
    std::cout << "Enter the no : ";
    std::cin >> a;
    std::cout << IsPrime(a) << std::endl;

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