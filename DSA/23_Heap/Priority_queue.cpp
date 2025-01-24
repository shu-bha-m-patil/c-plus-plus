#include <iostream>
#include <vector>
#include <algorithm>

struct PriorityQueue
{
    std::vector<int>_heap;

    void heapifyUp(int i)
    {
        int parent = (i - 1) / 2;
        if (i > 0 && _heap[i] > _heap[parent])
        {
            std::swap(_heap[i], _heap[parent]);
            heapifyUp(parent);
        }
    }

    void push(int iData)
    {
        _heap.push_back(iData);
        heapifyUp(_heap.size() - 1);
    }
    
    void printHeap()
    {
        std::cout << "Priority queue : ";
        for(int val : _heap)
            std::cout << val << " ";
        std::cout << std::endl;
    }

    int top()
    {
        if(_heap.size() >= 0) 
            return _heap[0];
        else
        {
            std::cout << "Heap is empty" << std::endl;
            return 0;
        }
    }

    void heapifyDown(int i)
    {
        if (_heap.size() <= 0)
            return;

        int li = i;
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;

        if (lc < _heap.size() && _heap[li] < _heap[lc])
            li = lc;
        if (rc < _heap.size() && _heap[li] < _heap[rc])
            li = rc;

        if (li != i)
        {
            int td = _heap[li];
            _heap[li] = _heap[i];
            _heap[i] = td;
            heapifyDown(li);
        }
    }

    void pop()
    {
        if(_heap.size() == 0) 
            _heap.pop_back();

        if(_heap.size() > 0)
        {
            _heap[0] = _heap[_heap.size() - 1];
            _heap.pop_back();
            heapifyDown(0);
        }
    }
};


int main() 
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(25);
    pq.push(35);
    pq.push(100);
    pq.push(2);

    std::cout << "Priority Queue (Heap Representation): ";
    pq.printHeap();

    std::cout << "Top element: " << pq.top() << std::endl; // Output: 30
    pq.pop();

    std::cout << "Priority Queue after pop: ";
    pq.printHeap();

    return 0;
}
