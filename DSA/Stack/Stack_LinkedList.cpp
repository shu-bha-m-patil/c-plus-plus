#include <iostream>
#include <stack>
#include <vector>

struct StackNode
{
	int _data;
	StackNode* _nextNode;
};

class Stack
{
	StackNode* _top;
public:
	Stack();
	StackNode* Gettop();
	void Push(int iData);
	void Pop();
	void Display();
};

Stack::Stack() : _top(NULL) {}

StackNode* Stack::Gettop() { return _top; }

void Stack::Push(int iData)
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

void Stack::Pop()
{
	if (_top == NULL)
	{
		std::cout << "Stack is empty, can't pop the element." << std::endl;
	}
	else
	{
		StackNode* pStackNode = _top;
		_top = _top->_nextNode;
		delete pStackNode; pStackNode = NULL;
	}
}

void Stack::Display()
{
	if (_top == NULL)
	{
		std::cout << "Stack is empty." << std::endl;
	}
	else
	{
		std::cout << "The Stack elements are : " << std::endl;
		StackNode* pStackNode = _top;
		while (pStackNode != NULL)
		{
			std::cout << pStackNode->_data << " ";
			pStackNode = pStackNode->_nextNode;
		}
		std::cout << std::endl;
	}
}

int Stack_LinkedList()
{
	Stack* stack = new Stack;
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	stack->Push(4);

	stack->Display();

	stack->Pop();
	stack->Pop();

	stack->Display();

	return 0;
}
