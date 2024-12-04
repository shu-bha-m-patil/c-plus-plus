#include <iostream>
struct StackA
{
	int _top;
	int _size;
	int* _array;

	StackA();
	StackA(int iTop, int iSize, int* iArray);

	bool IsFull();
	bool IsEmpty();
	void Display();

	void Pop();
	void Push(int iVal);
};

StackA::StackA()
{
	_top = -1;
	_size = 0;
	_array = NULL;
}

StackA::StackA(int iTop, int iSize, int* iArray)
{
	_top = iTop;
	_size = iSize;
	_array = iArray;
}

bool StackA::IsFull()
{
	if (_top >= _size - 1)
		return true;

	return false;
}

bool StackA::IsEmpty()
{
	if (_top < 0)
		return true;

	return false;
}

void StackA::Display()
{
	std::cout << "The Stack Elements Are : ";
	for (size_t i = 0; i <= _top; i++)
		std::cout << _array[i] << " ";

	std::cout << std::endl;
}

void StackA::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Can't Pop the element, Stack is empty." << std::endl;
		return;
	}

	--_top;
}

void StackA::Push(int iVal)
{
	if (IsFull())
	{
		std::cout << "Can't Push the element, Stack is Full." << std::endl;
		return;
	}

	++_top;
	_array[_top] = iVal;
}

int Stack_Array()
{
	const int size = 10;
	int array[size] = { 1, 2, 3, 4 };
	int top = 3;
	StackA* stack = new StackA(top, size, array);
	stack->Display();

	stack->Push(5);
	stack->Push(6);
	stack->Push(7);
	stack->Display();

	stack->Pop();
	stack->Pop();
	stack->Display();

	return 0;
}