#include <iostream>
#include <stack>

bool IsBalance(std::stack<char> iStack)
{
    std::stack<char> stack;
    bool isBalance = true;
    while (!iStack.empty())
    {
        char c = iStack.top();
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);
        else
        {
            if ((c == ')' && (stack.top() == '(')) ||
                (c == ']' && (stack.top() == '[')) ||
                (c == '}' && (stack.top() == '{')))
            {
                stack.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }
        iStack.pop();
    }
    return isBalance;
}

int main()
{
    std::stack<char> stack;
    stack.push(')');
    stack.push('}');
    stack.push(']');
    stack.push('[');
    stack.push('{');
    stack.push('(');
    if (IsBalance(stack))
        std::cout << "Stack is balanced." << std::endl;
    else
        std::cout << "Stack is not balanced." << std::endl;

    return 0;
}