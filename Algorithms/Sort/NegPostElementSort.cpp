#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int PosNegSeg(std::vector<int>& arr)
{
    int pos = - 1, neg = arr.size();
    while (true)
    {
        do
        {
            ++pos;
        } while (arr[pos] < 0);
        
        do
        {
            neg--;
        } while (arr[neg] > 0);

        if(pos >= neg) return neg;
        std::swap(arr[pos], arr[neg]);
    }
}

int main()
{
    std::vector<int> arr = {-12,18,-10,15};
    PrintArray (arr);

    PosNegSeg(arr);
    
    PrintArray (arr);
    return 0;
}


