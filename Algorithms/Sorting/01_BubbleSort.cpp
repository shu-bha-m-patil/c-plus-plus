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
    int arr[] = {5,8,10,20};
    int size = sizeof(arr) / sizeof(int);
    PrintArray (arr, size);
    
    // Bubble sort
    for (size_t j = 0; j < size; j++)
    {
        bool swap = false;

        for (size_t i = 1; i < size - j; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                int td = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = td;

                std::cout << "Count" << std::endl;
                swap = true;
            }
        }

        if(!swap) break;
    }

    PrintArray (arr, size);
    return 0;
}


