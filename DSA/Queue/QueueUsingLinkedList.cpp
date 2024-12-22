#include <iostream>

struct LinkedList
{
    int _data;
    LinkedList* _next;

    LinkedList(int iData)
    {
        _data = iData;
        _next = nullptr;
    }
};


struct QueueUsingLinkedList
{
    LinkedList* _head;
    LinkedList* _tail;
    int _size;

    QueueUsingLinkedList()
    {
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }

    void enque(int iVal)
    {
        LinkedList* newNode = new LinkedList(iVal);
        if(_head == nullptr)
            _head = newNode;
        else if(_head->_next == nullptr)
        {
            _tail = newNode;
            _head->_next = _tail;
        }
        else
        {
            _tail->_next = newNode;
            _tail = _tail->_next;
        }
        _size++;
    }
    
    void deque()
    {
        if(_head == nullptr)
            std::cout << "The queue is empty" << std::endl;
        else
        {
            LinkedList* temp = _head;
            _head = _head->_next;
            std::cout << "The pop element is " << temp->_data << std::endl;
            delete temp;
            _size--;
        }
    }

    int GetSize()
    {
        return _size;
    }

    void PrintQueue()
    {
        LinkedList* currNode = _head;
        while (currNode)
        {
            std::cout << currNode->_data << " " << std::endl;
            currNode = currNode->_next;
        }
    }
};

int main()
{
    QueueUsingLinkedList queue;
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
