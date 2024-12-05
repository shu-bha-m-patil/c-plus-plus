#include <iostream>

int main()
{
    int x = 3;
    int y = 6;

    std::cout << "The AND resutl is : " << (x & y);

    return 0;
}
/*
            11111
    2^ -->  43210
*/


/*
        3 - 0011
        6 - 0110    & operator
 result 2 - 0010
*/