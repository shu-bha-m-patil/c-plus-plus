#include <iostream>

int main()
{
    int arr[] = {-1,-8,-30,-5,-20,-7};
    int size = sizeof(arr) / sizeof(int);
   
    int k = 2;
    int sum = arr[0];
    for (size_t i = 1; i < k; i++)
    {
        sum += arr[i];
    }
    int maxSum = sum;
    for (size_t i = k; i < size; i++)
    {
        sum += arr[i] - arr[i - k];
        maxSum = std::max(sum, maxSum);
    }
    std::cout << "The max sum of " << k << " element is " << maxSum << std::endl;
}