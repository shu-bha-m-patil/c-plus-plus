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
    //int arr[] = {14,5,13,6,9,12,11,8};
    int arr[] = {50,30,20,10,5,11};
    //int arr[] = {70,60,80,40,30};
    //int arr[] = {30,40,50,20,80};
    int size = sizeof(arr) / sizeof(int);
    
    // Lomoto Partitian
    int l = 0, h = 5, p = 2;

    int td = arr[h];
    arr[h] = arr[p];
    arr[p] = td;

    p = h;
    
    int sm = l;
    for (size_t la = l; la < h; la++)
    {
        if(arr[la] < arr[p])
        {
            int td = arr[sm];
            arr[sm] = arr[la];
            arr[la] = td;
            sm++;
        }
    }
    
    td = arr[sm];
    arr[sm] = arr[p];
    arr[p] = td;
    PrintArray(arr, size);
    return 0;
}
