
#include <iostream>
#include <stack>

bool IsHigherParanthesis(std::stack<char> stack, char c)
{
    char top = stack.top();
    if ((c == '*' || c == '/') && (top == ('+') || top == ('-')))
        return true;
    return false;
}

std::string PrintPostfixString(std::string iInfixString)
{
    std::string postFixString;
    std::stack<char> stack;
    for (size_t i = 0; i < iInfixString.size(); ++i)
    {
        char c = iInfixString[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (stack.empty())
                stack.push(c);
            else
            {
                while (!stack.empty() && !IsHigherParanthesis(stack, c))
                {
                    char cc = stack.top();
                    stack.pop();
                    postFixString.push_back(cc);
                }
                stack.push(c);
            }
        }
        else
            postFixString.push_back(c);
    }

    while (!stack.empty())
    {
        postFixString.push_back(stack.top());
        stack.pop();
    }
    return postFixString;
}

int main()
{
    std::string infixString = "a+b/c-d*e";
    std::cout << "The postfix string is " << PrintPostfixString(infixString) << std::endl;
}