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
    while (l <= h)
    {
        int m = (h + l) / 2;
        if(k < arr[m]) { h = m - 1; }
        else if(arr[m]< k) { l = m + 1; }
        else { return m; }
    }
    return -1;
}

int FindInInfiniteArray(std::vector<int> arr, int k)
{
    if(arr.size() > 0 && arr[0] == k) return 0;

    int i = 1, l = 1, h = 1;
    while (arr[i] < k)
    {
        l = i;
        i = i*2;
    }
    h = i;
    return FindElementIndex(arr, l, h, k);
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    PrintArray (arr);

    int k = 8;
    std::cout << "The index of element is " << FindInInfiniteArray(arr, 8) << std::endl;
    
    return 0;
}


