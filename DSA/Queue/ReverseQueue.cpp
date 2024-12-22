#include <iostream>
#include <queue>
#include <stack>

void revrseQueue(std::queue<int> &iQueue)
{
    std::stack<int> stack;
    while (!iQueue.empty())
    {
        stack.push(iQueue.front());
        iQueue.pop();
    }

    while (!stack.empty())
    {
        iQueue.push(stack.top());
        stack.pop();
    }
}

void printQueue(std::queue<int> iQueue)
{
    std::queue<int> queue = iQueue;
    while (!queue.empty())
    {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}

std::queue<int> revrseQueueRecurcieve(std::queue<int> &iQueue)
{
    if(iQueue.empty())
        return iQueue;

    int val = iQueue.front();
    iQueue.pop();
    iQueue = revrseQueueRecurcieve(iQueue);
    iQueue.push(val);
    return iQueue;
}

void revrseQueueRecurcieve1(std::queue<int> &iQueue)
{
    if(iQueue.empty())
        return;

    int val = iQueue.front();
    iQueue.pop();
    revrseQueueRecurcieve1(iQueue);
    iQueue.push(val);
}

int main()
{
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    printQueue(queue);

    //queue = revrseQueueRecurcieve(queue);
    revrseQueueRecurcieve1(queue);

    printQueue(queue);

    return 0;
}
