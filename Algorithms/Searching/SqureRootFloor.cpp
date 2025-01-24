#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int SqureRootFloor(int x, int l, int h)
{
    int floor = -1;
    while (l <= h)
    {
        int m = (h + l) / 2;
        if (m*m > x)
            h = m - 1;
        else if(m*m < x)
        {
            l = m + 1;    
            floor = m;
        }
        else
            return m;
    }
    return floor;
}

int main()
{
    int x = 10;
    std::cout << "The floor of square root " << x << " is " << SqureRootFloor(x, 0, x) << std::endl;

    return 0;
}


