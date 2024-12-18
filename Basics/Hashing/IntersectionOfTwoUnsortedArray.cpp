#include <iostream>
#include <unordered_set>

int main()
{
    int arr[] = {10,15,20,25,30,50};
    size_t size = sizeof(arr)/sizeof(int);
    int arr2[] = {30,5,15,80};
    size_t size2 = sizeof(arr2)/sizeof(int);

    std::unordered_set<int> unorderedSet(arr2, arr2 + size2);
    for (size_t i = 0; i < size; i++)
        if(unorderedSet.find(arr[i]) != unorderedSet.end())
            std::cout << arr[i] << " ";
    std::cout << std::endl;
}