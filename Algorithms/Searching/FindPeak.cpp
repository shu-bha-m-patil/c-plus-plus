#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int FindPeakElement(std::vector<int> arr)
{
    size_t size = arr.size();

    if(size == 1) return arr[0];

    if(size == 2) { return arr[0] > arr[1] ? arr[0] : arr[1] ;}

    for (size_t i = 1; i < arr.size() - 1; i++)
    {
        if(arr[i - 1] <= arr[i] && arr[i] >= arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    std::vector<int> arr = {5,20,40,30,20,50,60};
    PrintArray (arr);
    
    std::cout << "The Peak element is " << FindPeakElement(arr) << std::endl;
    return 0;
}


