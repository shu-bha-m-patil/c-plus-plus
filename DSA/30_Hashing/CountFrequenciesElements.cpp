#include <iostream>
#include <unordered_map>

int main()
{
    int arr[10] = {0,2,2,4,4,6,6,8,8,9};
    std::unordered_map<int, int> unorderedMap;
    for (size_t i = 0; i < 10; i++)
        unorderedMap[arr[i]]++;

    for (auto mapElem : unorderedMap)
        std::cout << mapElem.first << " " << mapElem.second << std::endl;
}