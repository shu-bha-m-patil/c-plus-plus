#include <iostream>

int MaxSum(int* arr, int size)
{
    int maxSum = arr[0];
    int sum = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        sum = std::max(sum + arr[i], arr[i]);
        if(sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}

int main()
{
    int arr[] = {-10,5,-6,3,-4};
    int size = sizeof(arr) / sizeof(int);
    int maxSum = MaxSum(arr, size);

    if(maxSum < 0)
        std::cout << "The maxSum of circular sub arrays is : " << maxSum << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = -arr[i];
    }
    int rMaxSum = MaxSum(arr, size);
    int cirSum = maxSum + rMaxSum;
    std::cout << "The maxSum of circular sub arrays is : " << std::max(maxSum, cirSum) << std::endl;
}
