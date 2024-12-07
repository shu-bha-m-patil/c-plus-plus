#include <iostream>
#include <vector>
using namespace std;

long long GetSum(vector<int> &arr, long long sum, int i)
  {
    if(i == arr.size())
        return sum;
        
    sum = GetSum(arr, sum, i + 1);
    sum = sum + GetSum(arr, sum + arr[i], i + 1);
    return sum;
  }

int main()
{
    vector<int> arr = { 1,2,3 };
    long long subarrayRanges(vector<int> &arr);
    long long sum = 0;
    long long i = 0;
    std::cout << "The sum of sub arrays are : " << GetSum(arr, sum, i);
  

    int temp = 0;
    std::cin >> temp;
};
