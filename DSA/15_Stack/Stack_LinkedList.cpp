
#include <iostream>
struct LinkedList
{
    int _data;
    LinkedList* _next;

    LinkedList(int iVal)
    {
        _data = iVal;
        _next = nullptr;
    }
};

struct Stack
{
    LinkedList* _head;
    
    Stack()
    {
        _head = nullptr;
    }

    void Push(int iVal)
    {
        LinkedList* newNode = new LinkedList(iVal);
        if(_head == nullptr)
            _head = newNode;
        else
        {
            int data = _head->_data;
            newNode->_next = _head;
            _head = newNode;
        }
    }

    void Pop()
    {
        if(_head)
        {
            LinkedList* tempNode = _head;
            _head = _head->_next;
            delete tempNode;
        }
        else
        {
            std::cout << "Stack underflow" << std::endl;
        }
    }

    void Peek()
    {
        if(_head)
            std::cout << "The element is " << _head->_data << std::endl;
    }

    ~Stack()
    {
        delete _head; 
    }
};

int main()
{
    Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Peek();
    stack.Pop();
    stack.Peek();
    stack.Push(3);
    stack.Peek();
    stack.Pop();
    stack.Peek();
    stack.Pop();
    stack.Peek();
    stack.Pop();
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(5);
    stack.Peek();
    stack.Push(6);
    stack.Peek();
}