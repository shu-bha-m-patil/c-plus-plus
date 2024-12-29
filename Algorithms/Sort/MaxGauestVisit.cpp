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
    //<arriaval,departure>
    std::vector<std::pair<int,int>> arr = {{900,1000},{600,800},{700,730}};
    std::sort(arr.begin(), arr.end(), CostumComparator);
    PrintIntervals(arr);
    size_t ariv = 1, dep = 0, maxGuest = 0, curGuest = 1;
    while (ariv < arr.size())
    {
        if(arr[ariv].first <= arr[dep].second)
            curGuest++;
        else
            curGuest--;
        ariv++; dep++;
        maxGuest = std::max(maxGuest,curGuest);
    }
    std::cout << "Maximum no of guest can visit is " << maxGuest << std::endl;
    return 0;
}


