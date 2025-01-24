
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
    std::cout << "The postfix string is " << postFixString << std::endl;
    return postFixString;
}

int EvaluatePostfix(std::string iInfixString)
{
    std::string postfix = PrintPostfixString(iInfixString);
    std::stack<char> postFixStack;
    for (int i = postfix.size() - 1; i >= 0; i--)
    {
        char c = postfix[i];
        postFixStack.push(c);
    }

    int res1 = 0;
    int res2 = 0;
    std::stack<char> popStringStack;
    while (!postFixStack.empty())
    {
        char c = postFixStack.top();
        postFixStack.pop();
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (popStringStack.size() >= 2)
            {
                char c1 = popStringStack.top();
                popStringStack.pop();
                char c2 = popStringStack.top();
                popStringStack.pop();
                int c11 = c1 - '0';
                int c12 = c2 - '0';
                if (c == '+')
                    res1 = c12 + c11;
                else if (c == '-')
                    res1 = c12 - c11;
                else if (c == '*')
                    res1 = c12 * c11;
                else if (c == '/')
                    res1 = c12 / c11;
            }
            else
            {
                char cCurr = popStringStack.top();
                int cCurr11 = cCurr - '0';
                if (c == '+')
                    res2 = cCurr11 + res1;
                else if (c == '-')
                    res2 = cCurr11 - res1;
                else if (c == '*')
                    res2 = cCurr11 * res1;
                else if (c == '/')
                    res2 = cCurr11 / res1;
                res1 = 0;
            }

            if (res1 != 0 && res2 != 0)
            {
                char c = postFixStack.top();
                postFixStack.pop();
                if (c == '+' || c == '-' || c == '*' || c == '/')
                {
                    if (c == '+')
                        res2 = res2 + res1;
                    else if (c == '-')
                        res2 = res2 - res1;
                    else if (c == '*')
                        res2 = res2 * res1;
                    else if (c == '/')
                        res2 = res2 / res1;
                    res1 = 0;
                }
            }
        }
        else
        {
            popStringStack.push(c);
        }
    }
    return res2;
}

int main()
{
    std::string infixString = "2+8/2-3*5";
    int val = EvaluatePostfix(infixString);
    std::cout << "The Evaluation is " << val << std::endl;
}