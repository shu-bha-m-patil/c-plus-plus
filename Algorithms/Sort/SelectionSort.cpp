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
    int arr[] = {10,5,8,20,2,18};
    int size = sizeof(arr) / sizeof(int);
    PrintArray (arr, size);
    
    // Selection sort
    for (size_t j = 0; j < size - 1; j++)
    {
        int minIndex = j;
        for (size_t i = j + 1; i < size; i++)
        {
            if(arr[i] < arr[minIndex])
                minIndex = i;
        }

        if(minIndex != j)
        {
            int td = arr[j];
            arr[j] = arr[minIndex];
            arr[minIndex] = td;
            PrintArray (arr, size);
        }
    }

    PrintArray (arr, size);
    return 0;
}


