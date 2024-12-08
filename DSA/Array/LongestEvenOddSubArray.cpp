#include <iostream>

int main()
{
    int arr[] = {7,10,13,14};
    int size = sizeof(arr) / sizeof(int);
    int maxCount = 1;
    int curCount = 1;
    for (size_t i = 1; i < size; i++)
    {
        if(arr[i] % 2 != arr[i-1] % 2)
        {
            curCount++;
            maxCount = std::max(maxCount, curCount);
        }
        else
            curCount = 1;
    }
    
    std::cout << "The length of longest even odd sub array is : " << maxCount << std::endl;
}