#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool FindPairWithGivenSum(std::vector<int> arr, int sum)
{
    if(arr.size() < 3) return false;
    int s = arr[0] + arr[1] + arr[2];
    int i = 0, j = 2;
    while(j < arr.size())
    {
        if(s == sum) return true;
        else if(s < sum)
        {
            j++;
            s = s + arr[j] - arr[i];
            i++;
        }
        else 
            return false;
    }
    return false;
}

int main()
{
    std::vector<int> arr = {2,3,4,8,9,20,40};
    PrintArray (arr);
    
    int sum = 21;
    if(FindPairWithGivenSum(arr, sum))
        std::cout << "The triplate is present" << std::endl;
    else
        std::cout << "The triplate is not present" << std::endl;
    return 0;
}


