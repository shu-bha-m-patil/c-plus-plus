#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    size_t size = sizeof(arr) / sizeof(int);
    int k = 4;
    int freq = size / k;
    std::unordered_map<int, int> unMap;
    for (size_t i = 0; i < size; i++)
        unMap[arr[i]]++;

    for (auto distElem : unMap)
        if (distElem.second > freq)
            std::cout << distElem.first << " ";

    return 0;
}