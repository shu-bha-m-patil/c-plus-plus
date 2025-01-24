#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int givenSum = 4;
    int arr[] = {-1,5,8,3,1,5,-6,6,2,2};
    size_t size = sizeof(arr) / sizeof(int);
    int maxLenght = 0;
    int prefSum = 0;
    std::unordered_map<int, int> unorderedMap;
    for (int i = 0; i < size; i++)
    {
        prefSum = prefSum + arr[i];
        if(prefSum == givenSum)
        {   
            maxLenght = std::max(maxLenght, i);
            int zero = 0;
            std::cout << "Array indexes are " << zero << " " << i << std::endl;
        }
        
        std::unordered_map<int, int>::iterator it = unorderedMap.find(prefSum - givenSum);
        if (it != unorderedMap.end())
        {
            maxLenght = std::max(maxLenght, i - it->second);
            std::cout << "Array indexes are " << it->second + 1 << " " << i << std::endl;
        }
        unorderedMap.insert({prefSum, i});
    }

    std::cout << "The maximum lenght of sub array is " << maxLenght << std::endl;
}