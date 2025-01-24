#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int givenSum = 22;
    int arr[] = {5,8,6,13,3,-1};
    size_t size = sizeof(arr) / sizeof(int);

    int prefSum = 0;
    std::unordered_set<int> unorderedSet;
    for (size_t i = 0; i < size; i++)
    {
        prefSum = prefSum + arr[i];
        if(prefSum == givenSum)
            std::cout << "The sum array is present." << std::endl;
            
        if (unorderedSet.find(prefSum - givenSum) != unorderedSet.end())
            std::cout << "The sum array is present." << std::endl;
            
        unorderedSet.insert(prefSum);
    }
}