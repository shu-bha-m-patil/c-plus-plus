#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

std::pair<int, int> FindPairWithGivenSum(std::vector<int> arr, int sum)
{
    int i = 0, j = 0, ts = arr[0];
    while (j < arr.size())
    {
        if(ts < sum)
        {
            j++;
            ts = ts + arr[j];
        }
        else if(ts > sum)
        {
            ts = ts - arr[i];
            i++;
        }
        else
            return {i, j};
    }
    
    return {-1,-1};
}

int main()
{
    std::vector<int> arr = {5,20,40,30,20,50,60};
    PrintArray (arr);
    
    int sum = 50;
    std::pair<int, int> pair = FindPairWithGivenSum(arr, sum);
    std::cout << "The pair for given sum is {" << pair.first << "," << pair.second << "}" << std::endl;
    return 0;
}


