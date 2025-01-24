#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int arr[] = {10, 20, 10, 10, 30, 40};
    size_t size = sizeof(arr) / sizeof(int);
    int windowSize = 4;
    for (size_t i = 0; i <= size - windowSize; i++)
    {
        std::unordered_set<int> unorderedSet(arr + i, arr + i + windowSize);
        std::cout << "The no of distinct elements are " << unorderedSet.size() << std::endl;
    }
}