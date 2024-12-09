#include <iostream>

int main()
{
    int arr[] = {2,8,3,9,6,5,4};
    int size = sizeof(arr) / sizeof(int);

    int prefixSumArr[size];
    prefixSumArr[0] = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        prefixSumArr[i] = prefixSumArr[i - 1] + arr[i];
    }
    
    int sIndex = 2;
    int eIndex = 6;
    int sum = prefixSumArr[eIndex];
    if(sIndex != 0)
        sum = prefixSumArr[eIndex] - prefixSumArr[sIndex - 1];

    std::cout << "The sum from " << sIndex << " to " << eIndex << " is " << sum << std::endl;
}