#include <iostream>
#include <vector>
#include <queue>

void PrintKLargestElements(std::vector<int>arr, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (size_t i = 0; i < k; i++)
        minHeap.push(arr[i]);

    size_t size = arr.size();
    for (size_t i = k; i < size; i++)
    {
        if(arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    std::cout << "The largest elements are : ";
    while (!minHeap.empty())
    {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
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
    PrintKLargestElements(arr, 3);
    return 0;
}