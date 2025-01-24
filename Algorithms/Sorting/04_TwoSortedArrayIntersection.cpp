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
    int arr1[] = {10,10,20,20,40,60};
    int size1 = sizeof(arr1) / sizeof(int);
    PrintArray (arr1, size1);
    
    int arr2[] = {10,20,20,20};
    int size2 = sizeof(arr2) / sizeof(int);
    PrintArray (arr2, size2);
    
    int i1 = 0, i2 = 0;
    for (size_t i = 0; i < (size1 < size2 ? size1 : size2); i++)
    {
        if(i > 0 && arr1[i1 - 1] == arr1[i1]) {i1++; continue;}
        if(i > 0 && arr2[i2 - 1] != arr2[i2]) {i2++; continue;}
        if(arr1[i1] < arr2[i2]) { i1++; }
        else if(arr1[i1] > arr2[i2]) { i2++; }
        else { std::cout << arr1[i1] << " "; i1++, i2++; }
    }

    return 0;
}


