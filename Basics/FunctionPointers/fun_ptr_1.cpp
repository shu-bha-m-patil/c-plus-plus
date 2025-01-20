#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

int compute(int x, int y, int(*fun_ptr)(int, int))
{
    return fun_ptr(x, y);
}

int main()
{
    int x = 2, y = 3;
    std::cout << compute(x, y, add) << std::endl;
    std::cout << compute(x, y, multiply) << std::endl;
    return 0;
}