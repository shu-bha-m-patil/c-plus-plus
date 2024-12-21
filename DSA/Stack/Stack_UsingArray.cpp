
#include <iostream>

struct Stack
{
    int *_arr;
    int _cap;
    int _top;

    Stack(int cap)
    {
        _cap = cap;
        _top = -1;
        _arr = new int[_cap];
        for (size_t i = 0; i < _cap; i++)
            _arr[i] = -1;
    }

    void Push(int iVal)
    {
        ++_top;
        if (_top >= _cap)
        {
            std::cout << "Stack Overflow" << std::endl;
        }
        else
        {
            _arr[_top] = iVal;
        }
    }

    void Pop()
    {
        if (_top < 0)
            std::cout << "Underflow" << std::endl;
        else
            --_top;
    }

    int Peek()
    {
        if(_top >= 0 && _top < _cap)
        {
            std::cout << "The element is " << _arr[_top] << std::endl;
            return _arr[_top];
        }
        return -1;
    }
};

int main()
{
    Stack stack(5);
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