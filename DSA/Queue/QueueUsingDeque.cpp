#include <iostream>
#include <deque>

struct QueueUsingDeque
{
    std::deque<int>_container;

    void enque(int iVal)
    {
        _container.push_back(iVal);
    }
    
    void deque()
    {
        if (_container.size() > 0)
        {
            _container.pop_front();
        }
        else
        {
            std::cout << "The queue is empty" << std::endl;
        }
    }

    void PrintQueue()
    {
        for (size_t i = 0; i < _container.size(); i++)
        {
            std::cout << _container[i] << std::endl;
        }
    }
};

int main()
{
    QueueUsingDeque queue;
    queue.enque(1);
    queue.enque(2);
    queue.enque(3);
    queue.enque(4);
    queue.PrintQueue();
    queue.deque();
    queue.deque();
    queue.PrintQueue();
    queue.enque(5);
    queue.enque(6);
    queue.PrintQueue();
    queue.deque();
    queue.deque();
    queue.deque();
    queue.deque();
    queue.deque();
    queue.PrintQueue();
    queue.enque(1);
    queue.enque(2);
    queue.enque(3);
    queue.enque(4);
    queue.PrintQueue();
}
