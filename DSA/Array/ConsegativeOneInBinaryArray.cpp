#include <iostream>
#include <vector>
using namespace std;

int CountConsegativeOne(int* arr, int size)
{
    int count = 0;
    int maxCount = 0;
    for (size_t i = 0; i < size; i++)
    {
      if(arr[i] == 0)
        count = 0;
      else
        count++;

      if(count > maxCount)
        maxCount = count;   
    }
     return maxCount;
}

int main()
{
    int arr[] = {0,1,1,0,1,1,1,1};
    std::cout << "The sum of sub arrays are : " << CountConsegativeOne(arr, 8) << std::endl;
};
