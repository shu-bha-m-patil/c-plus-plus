#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = {-2,6,-4,-8};
    int n = sizeof(arr) / sizeof(int);
    auto compare = [](int x, int y){ return x < y;};
    std::sort(arr, arr + n, compare);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}