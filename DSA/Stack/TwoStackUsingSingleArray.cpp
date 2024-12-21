
#include <iostream>

struct Stack
{
    int *_arr;
    int _cap;
    int _top1, _top2;

    Stack(int cap)
    {
        _cap = cap;
        _top1 = -1;
        _top2 = cap;
        _arr = new int[_cap];
        for (size_t i = 0; i < _cap; i++)
            _arr[i] = -1;
    }

    void Push1(int iVal)
    {
        if (_top1 < _top2 - 1)
        {
            ++_top1;
            _arr[_top1] = iVal;
        }
        else
            std::cout << "Stack overflow";
    }

    void Pop1()
    {
        if (_top1 >= 0)
        {
            --_top1;
        }
        else
            std::cout << "Stack underflow" << std::endl;
    }

    void Push2(int iVal)
    {
        if (_top1 < _top2 - 1)
        {
            --_top2;
            _arr[_top2] = iVal;
        }
        else
            std::cout << "Stack overflow" << std::endl;
    }

    void Pop2()
    {
        if (_top2 < _cap)
        {
            ++_top2;
        }
        else
            std::cout << "Stack underflow" << std::endl;
    }

    void Peek1()
    {
        if (0 <= _top1 && _top1 < _cap)
        {
            std::cout << "The element is " << _arr[_top1] << std::endl;
        }
        else
            std::cout << "Out of stack" << std::endl;
    }

    void Peek2()
    {
        if (0 <= _top2 && _top2 < _cap)
        {
            std::cout << "The element is " << _arr[_top2] << std::endl;
        }
        else
            std::cout << "Out of stack" << std::endl;
    }
};

main()
{
    Stack stack(5);
    stack.Pop1();
    stack.Pop2();
    stack.Push1(1);
    stack.Push2(5);
    stack.Peek1();
    stack.Peek2();
    stack.Push1(2);
    stack.Push2(4);
    stack.Peek1();
    stack.Peek2();
    stack.Push1(3);
    stack.Push2(2);
    stack.Peek1();
    stack.Peek2();
    stack.Push1(4);
    stack.Peek1();
    stack.Peek2();
    stack.Pop1();
    stack.Pop2();
    stack.Peek1();
    stack.Peek2();
    stack.Pop1();
    stack.Pop2();
    stack.Peek1();
    stack.Peek2();
    stack.Pop1();
    stack.Pop2();
    stack.Peek1();
    stack.Peek2();
    stack.Pop1();
    stack.Peek1();
    stack.Peek2();
}