#include <iostream>

int main()
{
    int x = 3;
    int y = 6;

    std::cout << "The OR resutl is : " << (x | y);

    return 0;
}

/*
        3 - 0011
        6 - 0110    | operator
 result 7 - 0111
*/