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
    int arr1[] = {5,10,15,22};
    int size1 = sizeof(arr1) / sizeof(int);
    PrintArray (arr1, size1);

    int arr2[] = {7,12,17,22,25,26};
    int size2 = sizeof(arr2) / sizeof(int);
    PrintArray (arr2, size2);
    
    // Merge two sorted sort
    //const int size = size1 + size2;
    const int size = 10;
    int arr[size];
    int i1 = 0;
    int i2 = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(i1 >= size1) 
        {
            while (i2 < size2)
            {
                arr[i] = arr2[i2];
                i2++;
                i++;
            }
            break;
        }
        if(i2 >= size2) 
        {
            while (i1 < size1)
            {
                arr[i] = arr1[i1];
                i1++;
                i++;
            }
            break;
        }

        if (arr1[i1] <= arr2[i2])
        {
            arr[i] = arr1[i1];
            i1++;
        }
        else
        {
            arr[i] = arr2[i2];
            i2++;
        }
    }

    PrintArray (arr, size);
    return 0;
}


