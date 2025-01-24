#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int FirstOccuranceIndex(std::vector<int> arr, int l, int h, int k)
{
    if(l > h) return -1;

    int m = (h + l) / 2;
    if (k < arr[m])
    {
       return FirstOccuranceIndex(arr, l, m - 1, k);
    }
    else if (arr[m] < k)
    {
       return FirstOccuranceIndex(arr, m + 1, h, k);
    }
    else
    {
        if(m == 0 || arr[m - 1] != arr[m]) 
            return m;
        else
            return FirstOccuranceIndex(arr, l, m - 1, k);
    }
}


int LastOccuranceIndex(std::vector<int> arr, int l, int h, int k)
{
    if(l > h) return -1;

    int m = (h + l) / 2;
    if (k < arr[m])
    {
       return LastOccuranceIndex(arr, l, m - 1, k);
    }
    else if (arr[m] < k)
    {
       return LastOccuranceIndex(arr, m + 1, h, k);
    }
    else
    {
        if(m + 1 >= arr.size() || arr[m] != arr[m + 1]) 
            return m;
        else
            return LastOccuranceIndex(arr, m + 1, h, k);
    }
}

int main()
{
    std::vector<int> arr = {9,20,20,20,20,20,20,30,35,36};
    PrintArray (arr);

    int k = 20;
    int firstOcc = FirstOccuranceIndex(arr, 0, arr.size() - 1, k);
    int lastOcc = LastOccuranceIndex(arr, 0, arr.size() - 1, k);
    std::cout << "The no of occurances of " << k << " is " << lastOcc - firstOcc + 1 << std::endl;
    
    return 0;
}


