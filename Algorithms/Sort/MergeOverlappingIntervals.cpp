#include <iostream>
#include <vector>
#include <algorithm>

void PrintIntervals(std::vector<std::pair<int,int>>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << "Interval " << i + 1 << " is {" << arr[i].first << "," << arr[i].second << "}" << std::endl; 
    }
}

bool IsOverlapping(std::pair<int,int> int1, std::pair<int,int> int2)
{
    return (int2.first <= int1.second && int1.second <= int2.second) ||
           (int1.first <= int2.second && int2.second <= int1.second) ? true : false; 
}

bool CostumComparator(std::pair<int,int> int1, std::pair<int,int> int2)
{
    return int1.first < int2.first ? true : false;
}

int main()
{
    std::vector<std::pair<int,int>> arr = {{5,10},{3,15},{18,30},{2,7}};
    std::sort(arr.begin(), arr.end(), CostumComparator);
    PrintIntervals(arr);
    size_t i = 0;
    while (i < arr.size() - 1)
    {
        if(IsOverlapping(arr[i], arr[i + 1]))
        {
            arr[i].first = std::min(arr[i].first, arr[i + 1].first);
            arr[i].second = std::max(arr[i].second, arr[i + 1].second);
            arr.erase(arr.begin() + i + 1);
            PrintIntervals(arr);
        }
        else
            i++;
    }
    PrintIntervals(arr);
    return 0;
}


