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

int LomutoParitian(std::vector<int>& arr, int l, int h)
{
    int p = h;
    int sm = l, la = l;
    while (sm < h)
    {
        if(arr[sm] < arr[p])
        {
            std::swap(arr[sm], arr[la]);
            la++;
        }
        sm++;
    }
    std::swap(arr[la], arr[p]);
    return la;
}

void QuickSort(std::vector<int>& arr, int l, int h)
{
    if(l >= h) return;
    int p = LomutoParitian(arr, l, h); PrintArray(arr); // p - partitianIndex 
    // p -> This case is different in Hoare partitian  
    // -> because all the smaller elements are on left and it returns last smallest index as previos
    // p + 1 -> larger elements are on right of pivote 
    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, h);
}

int main()
{
    std::vector<int> arr = {9,20,30,60,40,50,20,10,5,11};
    PrintArray(arr);

    QuickSort(arr, 0, arr.size() - 1);
    PrintArray(arr);
    
    return 0; 
}
