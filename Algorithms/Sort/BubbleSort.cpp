#include <iostream>

void PrintArray(int* iArr, int iSize)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < iSize; i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {10,8,20,5};
    int size = sizeof(arr) / sizeof(int);
    PrintArray (arr, size);
    
    // Bubble sort


    PrintArray (arr, size);
    return 0;
}


