#include <iostream>

/*
* Find Kth bit of given no.
*/

int Power(int n, int k)
{
    if (k == 1)
        return n;

    if ((k % 2) == 0)
    {
        int pow = Power(n, k / 2);
        return pow * pow;
    }
    else
    {
        int pow = Power(n, k / 2);
        return pow * pow * n;
    }
}



int main()
{
    int n = 0;
    std::cout << "Enter the no : ";
    std::cin >> n;

    int k = 0;
    std::cout << "Enter the position : ";
    std::cin >> k;

    /*Right Shift*/
    /*By multiplying 2 with given power*/
    int rightShiftValue = n >> (k-1);
    if ((rightShiftValue & 1) == 1)
        std::cout << "The kth value is " << true << std::endl;
    else
        std::cout << "The kth value is " << false << std::endl;
    
    /*Left Shift*/
    /*By division 2 with given power*/
    int LeftShiftValue = 1 << (k - 1);
    if ((n & LeftShiftValue) == n)
        std::cout << "The kth value is " << true << std::endl;
    else
        std::cout << "The kth value is " << false << std::endl;
    //int powValue = Power(2, k - 1);
    //if ((n & powValue) == n)
    //    std::cout << "The kth value is " << true << std::endl;
    //else
    //    std::cout << "The kth value is " << false << std::endl;

    int temp = 0;
    std::cout << "Enter the no" << std::endl;
    std::cin >> temp;
    return 0;
}
