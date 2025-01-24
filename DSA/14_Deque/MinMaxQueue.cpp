#include <iostream>
#include <deque>

struct MinMaxQueue
{
    std::deque<int> _container;
    MinMaxQueue(size_t cap) : _container(cap)
    {
    }

    void InsertMin(int iVal)
    {
        if (_container.front() == 0)
            _container.push_front(iVal);
        else
        {
            if (iVal < _container.front())
                _container.push_front(iVal);
            else
                std::cout << "Can't insert. The value is more than the Min value." << std::endl;
        }
    }

    void InsertMax(int iVal)
    {
        if (_container.back() == 0)
            _container.push_back(iVal);
        else
        {
            if (_container.back() < iVal)
                _container.push_back(iVal);
            else
                std::cout << "Can't insert. The value is less than the Max value." << std::endl;
        }
    }

    int GetMin()
    {
        std::cout << "The min value is " << _container.front() << std::endl;
        return _container.front();
    }

    int GetMax()
    {
        std::cout << "The min value is " << _container.back() << std::endl;
        return _container.back();
    }
};

int main()
{
    size_t cap = 5;
    MinMaxQueue minMaxque(cap);
    minMaxque.InsertMin(5);
    minMaxque.InsertMax(6);
    minMaxque.GetMin();
    minMaxque.GetMax();
    minMaxque.InsertMin(4);
    minMaxque.InsertMax(7);
    minMaxque.GetMin();
    minMaxque.GetMax();
    minMaxque.InsertMin(8);
    minMaxque.InsertMax(3);
    minMaxque.GetMin();
    minMaxque.GetMax();
    return 0;
}
