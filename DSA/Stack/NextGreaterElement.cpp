#include <iostream>
#include <stack>

void PrintSpan(int *arr, int n)
{
    std::stack<int> stack;
    stack.push(0);
    std::cout << "The span is " << 1 << std::endl;
    for (size_t i = 1; i < n; i++)
    {
        while (!stack.empty() && arr[stack.top()] <= arr[i])
        {
            stack.pop();
        }
        if (stack.empty())
            std::cout << "The span indexes are " << 1 << " , " << i + 1 << std::endl;
        else
            std::cout << "The span indexes are " << stack.top() + 1 << " , " << i + 1 << std::endl;
        stack.push(i);
    }
}

int main()
{
    const int size = 6;
    int arr[size] = {18, 12, 13, 14, 11, 16};
    PrintSpan(arr, size);
}