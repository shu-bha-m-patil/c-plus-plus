#include <iostream>
#include <vector>
#include <algorithm>

void PrintArray(std::vector<int>& arr)
{
    std::cout << "The array elements are : ";
    size_t size = arr.size();
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int HoareParitian(std::vector<int>&arr, int l, int h)
{
    int pivot = arr[l];
    int la = l - 1, sm = h + 1; 
    while (true)
    {
        do
        {
            la++;
        } while (arr[la] < pivot);
        
        do
        {
            sm--;
        } while (arr[sm] > pivot);
        
        if(la >= sm ) return sm;

        std::swap(arr[la], arr[sm]);
        PrintArray(arr);
    }
}

void QuickSort(std::vector<int>& arr, int l, int h)
{
    if(l >= h) return;
        int p = HoareParitian(arr, l, h); PrintArray(arr); // p - partitianIndex 
        
    // p - 1 -> This case is different in lomuto partitian  
    // -> because all the smaller elements are on left of pivote and 
    // p + 1 -> larger elements are on right of pivote 
    QuickSort(arr, l, p); 
    QuickSort(arr, p + 1, h);
}

int main()
{
    std::vector<int> arr = {5,7,4,1,2,3};
    PrintArray(arr);

    QuickSort(arr, 0, arr.size() - 1);
    PrintArray(arr);
    
    return 0; 
}
