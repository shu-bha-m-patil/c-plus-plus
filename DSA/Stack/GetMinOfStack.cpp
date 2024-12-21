
#include <iostream>


struct AuxStack
{
    int *_arr;
    int _cap;
    int _top;

    AuxStack(int cap)
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
        {
            --_top;
        }
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

struct Stack
{
    int *_arr;
    int _cap;
    int _top;
    AuxStack* _auxStack;

    Stack(int cap)
    {
        _cap = cap;
        _top = -1;
        _arr = new int[_cap];
        for (size_t i = 0; i < _cap; i++)
            _arr[i] = -1;

        _auxStack = nullptr;
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
            if(_auxStack == nullptr)
            {
                _auxStack = new AuxStack(_cap);
                _auxStack->Push(iVal);
            }
            else if (_auxStack->_arr[_auxStack->_top] >= iVal)
            {
                _auxStack->Push(iVal);
            }
        }
    }

    void Pop()
    {
        if (_top < 0)
            std::cout << "Underflow" << std::endl;
        else
        {
            if(_auxStack->_top < 0)
                _auxStack->_top++;
            if(_arr[_top] <= _arr[_auxStack->_top])
                _auxStack->_top--;
            --_top;
        }
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

    int GetMin()
    {
        std::cout << "The min element is " << _auxStack->_arr[_auxStack->_top] << std::endl;
        return _auxStack->_top;
    }
};

int main()
{
    Stack stack(5);
    stack.Push(6);
    stack.Push(2);
    stack.GetMin();
    stack.Push(5);
    stack.GetMin();
    stack.Push(3);
    stack.GetMin();
    stack.Push(1);
    stack.GetMin();
}