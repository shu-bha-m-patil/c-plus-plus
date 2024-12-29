#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
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
    int p = LomutoParitian(arr, l, h);
    QuickSort(arr, l, p - 1);
    QuickSort(arr, p + 1, h);
}

int main()
{
    std::vector<int> arr = {10,3,20,12};
    PrintArray (arr);
    
    QuickSort(arr, 0, arr.size() - 1);
    PrintArray(arr);

    int minDiff = INT_MAX;
    for (size_t i = 1; i < arr.size(); i++)
        minDiff = std::min(minDiff, arr[i] - arr[i - 1]);
    
    std::cout << "The min difference is " << minDiff << std::endl;
    return 0;
}


