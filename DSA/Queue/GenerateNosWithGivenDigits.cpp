#include <iostream>
#include <queue>

void printQueue(std::queue<std::string> iQueue)
{
    std::queue<std::string> queue = iQueue;
    while (!queue.empty())
    {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}

int main()
{
    std::queue<std::string> queue;
    int n = 10;
    queue.push("5");
    queue.push("6");
    for (size_t i = 1; i < n / 2; i++)
    {
        std::string c = queue.front();
        std::cout << c << " ";
        queue.pop();
        queue.push(c + "5");
        queue.push(c + "6");
    }

    printQueue(queue);
    return 0;
}
