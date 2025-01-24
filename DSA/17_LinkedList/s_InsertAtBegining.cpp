#include <iostream>

struct LinkedList
{
	int _iData;
	LinkedList* _nextNode;
	LinkedList(int value)
	{
		_iData = value;
		_nextNode = NULL;
	}
	
	~LinkedList()
	{

	}
};

LinkedList* InsertAtTheBegin(LinkedList* iHead, int iValue)
{
	LinkedList* newHead = NULL;
	if(iHead == NULL)
	{
		newHead = new LinkedList(iValue);
	}
	else
	{
		newHead = new LinkedList(iValue);
		newHead->_nextNode = iHead;
	}
	return newHead;
}

void DisplayLinkedList(LinkedList* iHead)
{
	LinkedList* node = iHead;
	while (NULL != node)
	{
		std::cout << node->_iData << " ";
		node = node->_nextNode;
	}
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheBegin(head, 30);
	head = InsertAtTheBegin(head, 20);
	head = InsertAtTheBegin(head, 10);
	DisplayLinkedList(head);
	return 0;
}
