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

// Putes all the <= elements on left side
// Putes all the >= elements on left side
int HoareParitian(std::vector<int>&arr, int l, int h)
{
    int p = l;
    int pivot = arr[p];
    int la = l - 1, sm = h + 1; 
    // Large start from left to send large elements at back
    // small start from end to send small element at front
    // la --->>  <<--- sm //
    while (true)
    {
        do
        {
            la++;
        } while (arr[la] < pivot);
        
        do
        {
            sm--;
        } while (arr[sm] > pivot);
        
        if(la >= sm ) return sm;

        std::swap(arr[la], arr[sm]);
        PrintArray(arr);
    }
}

int main()
{
    //std::vector<int> arr = {20,21,22,23,24,10,11,20};
    //std::vector<int> arr = {21,22,23,24,10,11,20};
    std::vector<int> arr = {8,7,4,9,3,10,5};
    PrintArray(arr);

    int p = HoareParitian(arr, 0, arr.size() - 1);
    PrintArray(arr);
    std::cout << "The partitian index is : " << p << std::endl;
    return 0; 
}
