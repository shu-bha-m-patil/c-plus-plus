#include <iostream>
/*
* Is the given no is power of 2
*/

bool IsPowerOfTwo(int x)
{
    if (x == 0)
        return false;

    return ((x & (x - 1)) == 0);
}

int main()
{
    int x = 0;
    std::cout << "Enter the no ";
    std::cin >> x;
    std::cout << "Result : " << IsPowerOfTwo(x) << std::endl;

    int temp = 0;
    std::cout << "Enter a no : " << std::endl;
    std::cin >> temp;
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