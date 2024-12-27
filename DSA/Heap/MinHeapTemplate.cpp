#include <iostream>

struct MinHeap
{
    int* _arr;
    int _cap;
    int _size;

    MinHeap(int iCap) : _arr(nullptr), _cap(iCap), _size(0) {}

    int left(int i) { return 2*i + 1 ; }
    int right(int i) { return 2*i + 2 ; }
    int parent(int i) { return (i - 1) / 2 ; }
    
    
    void HeapifyDown(int parent)
    {
        
    }

    
    void HeapifyUp(int p)
    {
        int lc = p*2 + 1; if(lc >= _size) return;
        int rc = p*2 + 2; if(rc >= _size) return;

        // child swap index - ci
        int ci = 0;
        if(_arr[p] > _arr[lc]) ci = lc;
        if (_arr[p] > _arr[rc]) ci = rc;

        // temp data - td
        int td = _arr[ci];
        _arr[p] = _arr[ci];
        _arr[ci] = td;
        HeapifyUp(ci);
    }

    void Insert(int iData)
    {
        if (_size == 0) { std::cout << "Heap empty" << std::endl;}

        _arr[0] = _arr[_size - 1];
        _size--; 
        HeapifyDown(0);
    }
    
    void Pop(int iData)
    {
        if (_size == 0) { std::cout << "Stack overflow" << std::endl;}

        _size++; 
        _arr[_size] = iData;
        HeapifyUp(_size);
    }
};

int main()
{

}