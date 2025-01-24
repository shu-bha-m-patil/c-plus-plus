#include <iostream>

int GetTheNo(int* arr, int size)
{
    int result = 0;
    for (size_t i = 0; i < 9; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}

int main()
{
    const int size = 9;
    int arr[9] = { 4, 4, 7, 4, 8, 7, 7, 7, 8 };
    /*
    4 ^ 4 ^ 4 ^ 7 ^ 7 ^ 7 ^ 7 ^ 8 ^ 8
      0   ^ 4 ^   0   ^   0   ^   0
      0   ^ 4
      4
    */
    std::cout << "The odd courred no is " << GetTheNo(arr, size) << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}


/*
Properties of XOR operator

1 1 = 0
1 0 = 1
0 1 = 1
0 0 = 0


x ^ x = 0
x ^ 0 = x

Odd occurances  -->   x
    x ^ x ^ x = x
      0 ^ x   = x
Even occurances -->   0
  x ^ x ^ x ^ x = 0
    0   ^   0   = 0
*/