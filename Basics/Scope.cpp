#include <iostream>

// We can declare same variable name in different scope

int x = 20;

int main()
{
    int x = 10;
    {
        int x = 5;
        std::cout << x << std::endl;
    }
    std::cout << x << std::endl;
    return 0;
}