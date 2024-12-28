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
    int arr[] = {20, 5, 40, 60, 10, 30};
    int size = sizeof(arr) / sizeof(int);
    PrintArray(arr, size);

    // Insertion sort
    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    PrintArray(arr, size);
    return 0;
}
