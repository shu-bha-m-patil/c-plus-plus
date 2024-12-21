#include <iostream>
#include <stack>

void PrintNextGreaterElement(int *arr, int n)
{
    std::stack<int> stack;
    stack.push(n - 1);
    std::cout << "The next grater Element is " << -1 << std::endl;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!stack.empty() && arr[stack.top()] <= arr[i])
        {
            stack.pop();
        }
        if (stack.empty())
            std::cout << "The next grater Element is " << arr[0] << std::endl;
        else
            std::cout << "The next grater Element is " << arr[stack.top()] << std::endl;
        stack.push(i);
    }
}

int main()
{
    const int size = 6;
    int arr[size] = {18, 12, 13, 14, 11, 16};
    PrintNextGreaterElement(arr, size);
}