#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {9,20,30,60,40,50,20,10,5,11};
    PrintArray (arr);
    
    return 0;
}


