#include <iostream>

int main()
{
    int x = 112, y = 25, z = 87;

    // x is greater
    if(y > x)
        if(y > z)
            std::cout << "Y is greater" << std::endl;
        else
            std::cout << "Z is greater" << std::endl;
    else
        if(x > z)
            std::cout << "X is greater" << std::endl;
        else
            std::cout << "Z is greater" << std::endl;
        
    return 0;
}