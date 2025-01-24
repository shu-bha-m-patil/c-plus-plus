#include <iostream>
#include <vector>
#include <queue> 

void sortKth(std::vector<int>& arr, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (size_t i = 0; i <= std::min(k, (int)arr.size()); i++)
    {
        int td = arr[i];
        pq.push(td);
    }
    
    int index = 0;
    for (size_t i = k + 1; i < arr.size(); i++)
    {
        int td = pq.top(); pq.pop();
        arr[index++] = td;
    }

    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

void printHeap(std::vector<int>& arr)
{
    for(int arrEle : arr)
        std::cout << arrEle << " ";
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> arr = {9,8,7,19,18};
    std::cout << "The array elements are : ";
    printHeap(arr);

    int k = 2;
    sortKth(arr, 2);

    std::cout << "Sorted heap : ";
    printHeap(arr);

    return 0;
}
