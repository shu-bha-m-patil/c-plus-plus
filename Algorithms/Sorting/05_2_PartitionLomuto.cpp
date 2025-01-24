#include <iostream>
#include <vector>
#include <algorithm>

void PrintArray(std::vector<int>&arr)
{
    std::cout << "The array elements are : ";
    size_t size = arr.size();
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int LomutoParitian(std::vector<int>&arr, int l, int h)
{
    int p = h;
    int sm = l, la = l;
    while (sm < h)
    {
        if(arr[sm] < arr[p])
        {
            std::swap(arr[sm], arr[la]);
            la++;
            PrintArray(arr);
        }
        sm++;
    }
    std::swap(arr[la], arr[p]);
    return la;
}

int main()
{
    //std::vector<int> arr = {9,20,30,60,40,50,20,10,5,11};
    std::vector<int> arr = {8,7,4,9,3,10,5};
    PrintArray(arr);

    int ind = LomutoParitian(arr, 0, arr.size() - 1);
    PrintArray(arr);
    std::cout << "The Pivote index is : " << ind << std::endl;
    
    return 0; 
}
