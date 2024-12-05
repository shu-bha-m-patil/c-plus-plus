#include <iostream>

int Fib(int n)
{
    if (n == 0)
        return 0;
    
    if (n == 1)
        return 1;

    return Fib(n - 1) + Fib(n - 2);
}

void PrintTheFibSeries(int n)
{
    std::cout << "The fibonacci series till no " << n << " is ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << Fib(i) << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    int n = 0;
    std::cout << "Enter the no ";
    std::cin >> n;
    std::cout << "The fibonacci series no is " << Fib(n - 1) << std::endl;

    PrintTheFibSeries(n);

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
