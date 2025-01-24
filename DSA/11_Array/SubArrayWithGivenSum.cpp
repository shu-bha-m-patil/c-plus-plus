#include <iostream>

int main()
{
    int arr[] = {1,4,20,3,10,5};
    int size = sizeof(arr) / sizeof(int);
    int givenSum = 33;

    int sIndex = 0;
    int eIndex = 0;
    int sum = arr[0];
    while(eIndex < size)
    {
        if(sum > givenSum)
        {
            sum -= arr[sIndex];
            sIndex++;
        }
        else if(sum < givenSum)
        {
            eIndex++;
            sum += arr[eIndex];
        }
        else
        {
            std::cout << "The given sum " << givenSum << " is found from index " << sIndex << " to " << eIndex << std::endl;
            break;
        }

        if(sIndex == eIndex)
            break;
    }
}