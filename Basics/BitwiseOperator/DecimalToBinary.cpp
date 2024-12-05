#include <iostream>

int PrintBinaryNo(int n)
{
    if (n == 0)
        return 0;

    PrintBinaryNo(n / 2);
    std::cout << n % 2;
}

int main()
{
    int x = 0;
    std::cout << "Enter the no ";
    std::cin >> x;

    std::cout << "The Binary no is : ";
    PrintBinaryNo(x);
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}


/*
Properties of XOR operator

1 1 = 0
1 0 = 1
0 1 = 1
0 0 = 0


x ^ x = 0
x ^ 0 = x

Odd occurances  -->   x
    x ^ x ^ x = x
      0 ^ x   = x
Even occurances -->   0
  x ^ x ^ x ^ x = 0
    0   ^   0   = 0
*/