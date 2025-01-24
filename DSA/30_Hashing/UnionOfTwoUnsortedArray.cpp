#include <iostream>
#include <unordered_set>

int main()
{
    int arr[] = {10,30,10,40};
    size_t size = sizeof(arr)/sizeof(int);
    int arr2[] = {40,5,10,15};
    size_t size2 = sizeof(arr2)/sizeof(int);

    if(size > size2)
    {
        std::unordered_set<int> unorderedSet(arr, arr + size);

        for (size_t i = 0; i < size2; i++)
            unorderedSet.insert(arr2[i]);

        for(auto setElem : unorderedSet)
            std::cout << setElem << " ";
    }
    else
    {
        std::unordered_set<int> unorderedSet(arr2, arr2 + size2);
        for (size_t i = 0; i < size; i++)
            unorderedSet.insert(arr[i]);

        for(auto setElem : unorderedSet)
            std::cout << setElem << " ";

    }
    std::cout << std::endl;
}