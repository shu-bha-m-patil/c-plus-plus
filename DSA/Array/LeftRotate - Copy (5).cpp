#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    //std::sort(numbers.begin(), numbers.end());
    int leftIndex = 0;
    int rightIndex = numbers.size() - 1;
    int sum = 0;
    vector<int> resultIndex;

    while (leftIndex < rightIndex)
    {
        sum = numbers[rightIndex] + numbers[leftIndex];
        if (sum > target)
            rightIndex--;
        else if (sum < target)
            leftIndex++;
        else
        {
            resultIndex.push_back(leftIndex + 1);
            resultIndex.push_back(rightIndex + 1);
        }
    }
    return resultIndex;
}

int main()
{
    vector<int> numbers = { 2,7,11,15 };
    int target = 9;
    vector<int> resVect = twoSum(numbers, target);

    int temp = 0;
    std::cin >> temp;
};