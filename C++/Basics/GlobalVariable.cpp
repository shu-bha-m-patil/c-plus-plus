#include <iostream>

 // Global variables are initialize by compilers
 // But local variables are not initialize by compilers

extern int x;
double y;
char c;
int x = 10;

int main()
{
    int xx;

    int x = 5;
    double yy;
    char cc;

    std::cout << x << std::endl;
    std::cout << xx << std::endl;
    std::cout << y << std::endl;
    std::cout << yy << std::endl;
    std::cout << (int)c << std::endl;
    std::cout << (int)cc << std::endl;
    return 0;
}
