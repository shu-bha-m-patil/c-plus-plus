#include <iostream>

int main()
{
    int arr[] = {0,0,1,1,1,0,0,0,1,1,0,1,0,0,1};
    int size = sizeof(arr) / sizeof(int);
    for (size_t i = 1; i < size; i++)
    {
        if(arr[i - 1] != arr[i])
        {
            if(arr[0] != arr[i]) // starting
            {
                std::cout << i << ",";
                if((size - 1) == (i))
                    std::cout << i << ",";
            }
            else // ending
                std::cout << i - 1 << " ";
        }
    }

    
}