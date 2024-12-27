#include <iostream>
#include <vector>
#include <queue>

void PrintKClosetElements(std::vector<int>arr, int k, int val)
{
    std::priority_queue<std::pair<int, int>> maxHeap;

    for (size_t i = 0; i < k; i++)
        maxHeap.push({std::abs(arr[i] - val), i});

    size_t size = arr.size();
    for (size_t i = k; i < size; i++)
    {
        if(std::abs(arr[i] - val) < maxHeap.top().first)
        {
            maxHeap.pop();
            maxHeap.push({std::abs(arr[i] - val), i});
        }
    }

    std::cout << "The closest elements are : ";
    while (!maxHeap.empty())
    {
        std::cout << arr[maxHeap.top().second] << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;
}

void PrintVect(std::vector<int>& arr)
{
    std::cout << "The vector elements are : ";
    for(int arrEle : arr)
        std::cout << arrEle << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {5,15,10,20,8,25,18};
    PrintVect(arr);
    PrintKClosetElements(arr, 3, 17);
    return 0;
}