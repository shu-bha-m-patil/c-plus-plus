#include <iostream>
#include <stack>

void DisplayString(const char* iString)
{
	int i = 0;
	std::cout << "String ";
	while (iString[i] != '\0')
	{
		std::cout << iString[i];
		i++;
	}
	std::cout << std::endl;
}

bool IsOperator(char iChar)
{
	if (iChar == '-' || iChar == '+' || iChar == '*' || iChar == '/') return true;
	return false;
}

int GetPrecedence(char iChar)
{
	if (iChar == '*' || iChar == '/') return 2;
	if (iChar == '-' || iChar == '+') return 1;
	return 0;
}

bool IsPrecedenceGreater(std::stack<char> iStack, char iChar)
{
	char lastOpr = '1';
	if(!iStack.empty())
	lastOpr = iStack.top();
	return GetPrecedence(iChar) > GetPrecedence(lastOpr);
}

char* InfixToPostFix(const char* iInfixString)
{
	std::stack<char> stack;

	char* postFixString = new char[30];

	int i = 0; int j = 0;
	while (iInfixString[i] != '\0')
	{
		char currentChar = iInfixString[i];
		if (IsOperator(currentChar))
		{
			if (IsPrecedenceGreater(stack, currentChar))
			{
				stack.push(currentChar);
				i++;
			}
			else
			{
				char lastChar = stack.top();
				postFixString[j] = lastChar;
				stack.pop();
				j++;
			}

		}
		else
		{
			postFixString[j] = currentChar;
			i++;
			j++;
		}


	}

	while(!stack.empty())
	{
		char lastChar;
		if (!stack.empty())
			lastChar = stack.top();
		postFixString[j] = lastChar; j++;
		stack.pop();
	}

	return postFixString;
}

int Stack_InfixToPostfix()
{
	const char* infix = "a-b"; DisplayString(infix);
	char* postFixString = InfixToPostFix(infix); DisplayString(postFixString); delete[]postFixString;
	return 0;
}