#include <iostream>

 // sizeof -> Compile time operator, does not increaments x

int main()
{
    int x = 10;
    std::cout << sizeof(x++) << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;
    return 0;
}