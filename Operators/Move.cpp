#include <iostream>

void Move(char c, int &x, int &y)
{
    switch (c)
    {
    case 'R':
    {
        x++;
        break;
    }
    case 'L':
    {
        x--;
        break;
    }
    case 'U':
    {
        y++;
        break;
    }
    case 'D':
    {
        y--;
        break;
    }
    default:
    {
        std::cout << "Invalid Character" << std::endl;
    }
    }
    std::cout << x << " " << y << std::endl;
}

int main()
{
    char c = ' ';
    int x = 0, y = 0;
    while (x < 10 && y < 10)
    {
        std::cin >> c;
        Move(c, x, y);
    }
    return 0;
}