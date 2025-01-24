#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> resVect;
    std::unordered_map<int, int> uoMap;
    for (int i = 0; i < nums.size(); i++)
    {
        int res = target - nums[i];
        auto it = uoMap.find(res);
        if (it == uoMap.end())
        {
            uoMap.insert({nums[i], i});
        }
        else
        {
            resVect.push_back(it->second);
            resVect.push_back(i);
            return resVect;
        }
    }
}

int main()
{
    std::vector<int> vect = {2, 7, 11, 15};
    twoSum(vect, 9);
    return 0;
}