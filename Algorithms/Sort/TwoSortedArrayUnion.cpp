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
    int s1 = sizeof(arr1) / sizeof(int);
    PrintArray (arr1, s1);
    
    int arr2[] = {10,20,20,20};
    int s2 = sizeof(arr2) / sizeof(int);
    PrintArray (arr2, s2);
    
    int i1 = 0, i2 = 0;
    while(i1 < s1 && i2 < s2)
    {
        if(i1 > 0 && arr1[i1 - 1] == arr1[i1]) {i1++; continue;}
        if(i2 > 0 && arr2[i2 - 1] == arr2[i2]) {i2++; continue;}
        if(arr1[i1] < arr2[i2]) { std::cout << arr1[i1] << " "; i1++; }
        else if(arr1[i1] > arr2[i2]) { std::cout << arr2[i2] << " "; i2++; }
        else { std::cout << arr1[i1] << " "; i1++, i2++; }
    }

    while (i1 < s1) { std::cout << arr1[i1] << " "; i1++; }
    while (i2 < s2) { std::cout << arr2[i2] << " "; i2++; }
    return 0;
}


