#include <iostream>
#include<cmath>

void PrintSteps(int n, char a, char b, char c)
{
    if (n == 1)
    {
        std::cout << "Move 1 from " << a << " to " << c << "." << std::endl;
        return;
    }

    PrintSteps(n - 1, a, c, b);
    std::cout << "Move " << n << " from " << a << " to " << c << "." << std::endl;
    PrintSteps(n - 1, b, a, c);
}

int main()
{
    PrintSteps(5, 'a', 'b', 'c');
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}

// 3 a, b, c
//
// 2 a, c, b
// 