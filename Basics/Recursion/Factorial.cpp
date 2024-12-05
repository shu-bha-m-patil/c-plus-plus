#include <iostream>

int Fact(int n)
{
    if (n == 1)
        return 1;

    return n * Fact(n - 1);
}

int main()
{
    int n = 0;
    std::cout << "Enter the no ";
    std::cin >> n;
    std::cout << "The factorial of no is " << Fact(n) << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
