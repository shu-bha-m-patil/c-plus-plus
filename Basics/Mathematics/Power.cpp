#include <iostream>

int Power(int a, int n)
{
    if (n == 1)
        return a;

    if ((n % 2) == 0)
    {
        int temp = Power(a, n / 2);
        return temp * temp;
    }
    else
    {
        int temp = Power(a, n / 2);
        return temp * temp * a;
    }
}


int main()
{
    int a = 0, b = 0;
    std::cout << "Enter the no : ";
    std::cin >> a;
    std::cout << "Enter the power : ";
    std::cin >> b;
    std::cout << "The power of " << a << "^" << b << " is " << Power(a, b) << std::endl << std::endl;

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