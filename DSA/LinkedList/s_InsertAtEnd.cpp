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

LinkedList* InsertAtTheEnd(LinkedList* iHead, int iValue)
{
	LinkedList* newNode = new LinkedList(iValue);
	if(iHead == NULL)
	{
		iHead = newNode;
		return iHead;
	}

	LinkedList* tempNode = iHead;
	while (NULL != tempNode->_nextNode)
	{
		tempNode = tempNode->_nextNode;
	}

	tempNode->_nextNode = newNode;
	return iHead;
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
	head = InsertAtTheEnd(head, 30);
	head = InsertAtTheEnd(head, 20);
	head = InsertAtTheEnd(head, 10);
	DisplayLinkedList(head);
	return 0;
}
