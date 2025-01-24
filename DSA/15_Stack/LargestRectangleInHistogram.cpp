#include <iostream>
#include <stack>

void LargestRectangleInHistogram(int *arr, int n)
{
    std::stack<int> stack;
    stack.push(0);
    //std::cout << "The next grater Element is " << -1 << std::endl;
    int maxArea = arr[stack.top()];
    for (int i = 1; i < n; i++)
    {
        while (!stack.empty() && arr[stack.top()] > arr[i])
        {
            stack.pop();
        }
        if (stack.empty())
        {
            maxArea = std::max(maxArea, arr[i]*i);
            //std::cout << "The next grater Element is " << arr[i] << std::endl;
        }
        else
        {
            int j = stack.top();
            while (j <= i)
            {
                maxArea = std::max(maxArea, arr[j]*(i - j + 1));
                j++;
            }
            
            //std::cout << "The next grater Element is " << arr[stack.top()] << std::endl;
        }
        stack.push(i);
    }
    std::cout << "The max area is " << maxArea << std::endl;
}

int main()
{
    const int size = 9;
    int arr[size] = {60,20,50,20,20,40,10,50,60};
    LargestRectangleInHistogram(arr, size);
}