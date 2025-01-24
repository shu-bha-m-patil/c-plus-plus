#include <iostream>

int SubValue(int a, int b)
{
    if (a == b)
        return a;

    if (a > b)
        return SubValue(a - b, b);
    else
        return SubValue(a, b - a);
}

int EuclideanDivisor(int a, int b)
{
    if (b == 0)
        return a;

    return EuclideanDivisor(b, a % b);
}

int main()
{
    int a = 0, b = 0;
    std::cout << "Enter the value of a : ";
    std::cin >> a;

    std::cout << "Enter the value of b : ";
    std::cin >> b;

    int HCF = SubValue(a, b);
    std::cout << "The LCM is " << (a*b) / HCF << std::endl;

    HCF = EuclideanDivisor(a, b);
    std::cout << "The LCM is " << (a * b) / HCF << std::endl;
    
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