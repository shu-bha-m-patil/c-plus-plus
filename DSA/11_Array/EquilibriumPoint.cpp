#include <iostream>

int main()
{
    int arr[] = {3,4,8,-9,9,7};
    int size = sizeof(arr) / sizeof(int);

    int prefSum[size];
    prefSum[0] = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        prefSum[i] = prefSum[i - 1] + arr[i];
    }
    
    int suffixSum[size];
    suffixSum[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }

    for (size_t i = 0; i < size; i++)
    {
        if((prefSum[i] - suffixSum[i]) == 0)
            std::cout << "The equilibrium point is " << i << std::endl;
    }
}