//Paranthesis Problem

#include <iostream>

struct StackNode
{
	char _data;
	StackNode* _nextNode;
};

class StackL
{
	StackNode* _top;
public:	StackL();
	  StackNode* Gettop();
	  void Push(char iData);
	  void Pop();
	  void Display();
	  int IsParanthesisBalance(char* exp);
	  int IsEmpty();
	  int IsMatching(char* exp);
};

StackL::StackL() : _top(NULL) {}

StackNode* StackL::Gettop() { return _top; }

void StackL::Push(char iData)
{
	StackNode* pStackNode = new StackNode;
	pStackNode->_data = iData;

	if (_top == NULL)
	{
		_top = pStackNode;
		_top->_nextNode = NULL;
	}
	else
	{
		pStackNode->_nextNode = _top;
		_top = pStackNode;
	}
}

void StackL::Pop()
{
	if (_top == NULL)
	{
		std::cout << "StackL is empty, can't pop the element." << std::endl;
	}
	else
	{
		StackNode* pStackNode = _top;
		_top = _top->_nextNode;
		delete pStackNode; pStackNode = NULL;
	}
}

int StackL::IsEmpty()
{
	if (NULL == _top)
		return 1;
	return 0;
}

void StackL::Display()
{
	if (_top == NULL)
	{
		std::cout << "StackL is empty." << std::endl;
	}
	else
	{
		std::cout << "The StackL elements are : " << std::endl;
		StackNode* pStackNode = _top;
		while (pStackNode != NULL)
		{
			std::cout << pStackNode->_data << " ";
			pStackNode = pStackNode->_nextNode;
		}
		std::cout << std::endl;
	}
}

int StackL::IsMatching(char* exp)
{
	if (_top->_data == '(' && ')' == *exp)
		return 1;
	else if (_top->_data == '[' && ']' == *exp)
		return 1;
	else if (_top->_data == '{' && '}' == *exp)
		return 1;
	else
		return 0;
}

int StackL::IsParanthesisBalance(char* exp)
{
	while (*exp)
	{
		if (*exp == '(' || *exp == '{' || *exp == '[')
			Push(*exp);
		else if (*exp == ')' || *exp == ']' || *exp == '}')
		{
			if (IsEmpty())
				return 0;

			if (IsMatching(exp))
				Pop();
			else
				return 0;
		}
		exp++;
	}

	if (IsEmpty())
		return 1;

	return 0;
}

int StackL_ParanthesisProblem()
{
	char arr[100] = "({[(sd)]}f(sd)])";
	char* exp = arr;

	StackL stack;
	if (stack.IsParanthesisBalance(exp))
		std::cout << "Paranthesis is balanced.";
	else
		std::cout << "Paranthesis is not balanced.";

	return 0;
}
