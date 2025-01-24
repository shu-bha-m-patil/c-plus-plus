#include <iostream>
#include <unordered_set>

int main()
{
    int arr[10] = {0,2,2,4,4,6,6,8,8,9};
    // std::unordered_set<int> unorderedSet;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     unorderedSet.insert(arr, arr + 10);
    // }

    std::unordered_set<int> unorderedSet(arr, arr + 10);
    std::cout << "The size of distict elements is " << unorderedSet.size() << std::endl;
}