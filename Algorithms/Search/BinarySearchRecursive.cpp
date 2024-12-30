#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int FindElementIndex(std::vector<int> arr, int l, int h, int k)
{
    if(l > h) return -1;

    int m = (h + l) / 2;
    if (k < arr[m])
    {
       return FindElementIndex(arr, l, m - 1, k);
    }
    else if (arr[m] < k)
    {
       return FindElementIndex(arr, m + 1, h, k);
    }
    else
    {
        return m;
    }
}

int main()
{
    std::vector<int> arr = {10,20,30,40,50,60,70,80,90};
    PrintArray (arr);
    
    int k = 10;
    int kIndex = FindElementIndex(arr, 0, arr.size() - 1, k);
    if(kIndex >= 0)
        std::cout << "The search element index is " << kIndex << std::endl;
    else
        std::cout << "Element not found " << kIndex << std::endl;
    return 0;
}

