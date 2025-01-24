#include <iostream>

/*
* Find no of 1 in binaray formate of given no
* Solution
* n = 40        -->   101000
*  (n - 1) = 39 -->   100100    (Last one and rest zeros get reverse)
*       40 & 39 -->   100000    -->     32
* (32 - 1) - 31 -->   011111
*       32 & 31 -->   000000    -->     00
*/

int main()
{
    int n = 0;
    std::cout << "Enter the no : ";
    std::cin >> n;

    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    std::cout << "The no of 1 in binaray formate of given no are : " << count << std::endl;

    int temp = 0;
    std::cout << "Enter the no ";
    std::cin >> temp;
    return 0;
}
