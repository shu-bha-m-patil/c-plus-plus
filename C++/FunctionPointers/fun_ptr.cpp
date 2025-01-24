#include <iostream>

int print(int x, int y)
{
    return x = y;
}

int main()
{
    int (*fun_ptr)(int, int) = print;
    std::cout << fun_ptr(10,20) << std::endl;
    return 0;
}
