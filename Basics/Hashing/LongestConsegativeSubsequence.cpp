#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int arr[] = {1,3,4,3,3,2,9,10};
    size_t size = sizeof(arr) / sizeof(int);

    int maxCount = 0;
    std::unordered_set<int> unorderedSet(arr, arr + size);
    for (size_t i = 0; i < size; i++)
    {
       if(unorderedSet.find(arr[i] - 1) == unorderedSet.end())
       {
            int count = 1;
            while (unorderedSet.find(arr[i] + count) != unorderedSet.end())
                count++;
            maxCount = std::max(maxCount, count);
       }
    }
    std::cout << "The length of longest consegative subsequence sub array is " << maxCount << std::endl;
}