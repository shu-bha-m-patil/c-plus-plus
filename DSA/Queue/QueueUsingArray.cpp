#include <iostream>

struct QueueUsingArray
{
    size_t _cap;
    size_t _size;
    int _front;
    int *_arr;

    QueueUsingArray(size_t cap) : _cap(cap), _size(0), _front(0)
    {
        _arr = new int[cap];
    }

    void enque(int iVal)
    {
        if (_size >= _cap)
            std::cout << "Queue is full" << std::endl;
        else
        {
            int rear = 0;
            if (_size <= 0)
                rear = -1;
            else
                rear = (_front + _size - 1) % _cap;
            rear = (rear + 1) % _cap;
            _arr[rear] = iVal;
            _size++;
        }
    }

    void deque()
    {
        if (_size <= 0)
            std::cout << "Queue is empty" << std::endl;
        else
        {
            std::cout << "The pop element is " << _arr[_front] << std::endl;
            _front = (_front + 1) % _cap;
            --_size;
        }
    }

    void PrintQueue()
    {
        int logicalIndex = _front;
        for (size_t i = 0; i < _size; i++)
        {
            std::cout << _arr[logicalIndex] << " " << std::endl;
            logicalIndex = (logicalIndex + 1) % _cap;
        }
    }
};

int main()
{
    QueueUsingArray queue(5);
    queue.enque(1);
    queue.enque(2);
    queue.enque(3);
    queue.PrintQueue();
    queue.deque();
    queue.deque();
    queue.PrintQueue();
    queue.enque(4);
    queue.enque(5);
    queue.enque(6);
    queue.enque(7);
    queue.PrintQueue();
    queue.enque(8);
    queue.enque(9);
    queue.deque();
    queue.PrintQueue();
    queue.enque(10);
    queue.PrintQueue();
    queue.deque();
    queue.deque();
    queue.PrintQueue();
    return 0;
}