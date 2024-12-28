#include <iostream>

void PrintArray(int* iArr, int iSize)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i <= iSize; i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

int HoarePartitian(int* arr, int l, int h, int p)
{
    int li = l - 1, ri = h + 1;
    int pivot = arr[p];
    while (true)
    {
        do
        {
            li++;
        }
        while (arr[li] < pivot);

        do
        {
            ri--;
        }
        while (arr[ri] > pivot);
        
        if(li > ri) break;

        int td = arr[li];
        arr[li] = arr[ri];
        arr[ri] = td;
        PrintArray(arr, h);
    }
    PrintArray(arr, h);
    return ri;
}

int main()
{
    //int arr[] = {50,30,20,10,5,11};
    //int arr[] = {70,60,80,40,30};
    int arr[] = {30,40,50,20,80};
    //int arr[] = {14,5,13,6,9,12,11,8};
    int size = sizeof(arr) / sizeof(int);
    PrintArray(arr, size - 1);
    
    std::cout << "The pivot element is " << arr[HoarePartitian(arr, 0, size - 1, 0)] << std::endl;
    return 0;
}
