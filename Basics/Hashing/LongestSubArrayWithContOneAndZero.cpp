#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int arr[] = {1,0,1,1,1,0,0};
    size_t size = sizeof(arr) / sizeof(int);
    std::vector<int> vectWith_ve(size);
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i] == 0)
            vectWith_ve.push_back(-1);
        else
            vectWith_ve.push_back(1);
    }
    

    int maxLenght = 0;
    int prefSum = 0;
    std::unordered_map<int, int> unorderedMap;
    for (int i = 0; i < size; i++)
    {
        prefSum = prefSum + vectWith_ve[i];
        if(prefSum == 0)
            maxLenght = std::max(maxLenght, i);
        
        std::unordered_map<int, int>::iterator it = unorderedMap.find(prefSum);
        if (it != unorderedMap.end())
            maxLenght = std::max(maxLenght, i - it->second);
            
        unorderedMap.insert({prefSum, i});
    }

    std::cout << "The maximum lenght of sub array is " << maxLenght << std::endl;
}