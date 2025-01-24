#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int FindElementIndex(std::vector<int> arr, int k)
{
    int l = 0, m = 0, h = arr.size() - 1;
    while (l <= h)
    {
        m = (h + l) / 2;
        if(k < arr[m]) { h = m - 1; }
        else if(arr[m]< k) { l = m + 1; }
        else { return m; }
    }
    return -1;
}

int main()
{
    std::vector<int> arr = {9,20,30,60,40,50,20,10,5,11};
    PrintArray (arr);
    
    return 0;
}


