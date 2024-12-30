#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int FirstElementIndex(std::vector<int> arr, int l, int h, int k)
{
    if(l > h) return -1;

    int m = (h + l) / 2;
    if (k < arr[m])
    {
       return FirstElementIndex(arr, l, m - 1, k);
    }
    else if (arr[m] < k)
    {
       return FirstElementIndex(arr, m + 1, h, k);
    }
    else
    {
        if(m == 0 || arr[m - 1] != arr[m]) 
            return m;
        else
            return FirstElementIndex(arr, l, m - 1, k);
    }
}

int main()
{
    std::vector<int> arr = {0,0,0,0,1,1,1,1,1,1};
    PrintArray (arr);
    
    int k = 1;
    int kIndex = FirstElementIndex(arr, 0, arr.size() - 1, k);
    if(kIndex >= 0)
        std::cout << "The search element index is " <<  arr.size() - kIndex << std::endl;
    else
        std::cout << "Element not found " <<  arr.size() - kIndex << std::endl;
    return 0;
}

