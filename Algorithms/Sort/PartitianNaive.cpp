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
    int arr[] = {5,13,6,9,12,11,8};
    int size = sizeof(arr) / sizeof(int);
    PrintArray (arr, size);
    
    // Bubble sort
    int l = 0, h = 6, p = 6;

    //size_t tArrSize = h - l + 1;
    int index = 0;
    int tArray[5];
    for (size_t i = l; i <= h; i++)
    {
        if(arr[i] < arr[p] && i != p) { tArray[index] = arr[i]; index++;}
    }
    tArray[index] = arr[p]; index++;
    for (size_t i = l; i <= h; i++)
    {
        if(arr[i] > arr[p] && i != p) { tArray[index] = arr[i]; index++;}
    }

    for (size_t i = 0; i <= h - l + 1; i++)
        arr[l + i] = tArray[i];
    
    PrintArray (arr, size);
    return 0;
}


