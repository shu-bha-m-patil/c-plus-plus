#include <iostream>

struct LinkedList
{
	int _iData;
	LinkedList* _next;
	LinkedList(int value)
	{
		_iData = value;
		_next = NULL;
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
	while (NULL != tempNode->_next)
	{
		tempNode = tempNode->_next;
	}

	tempNode->_next = newNode;
	return iHead;
}

LinkedList* InsertAtGivenKey(LinkedList* iHead, int iData)
{
	LinkedList* newNode = new LinkedList(iData);
	if(iHead == NULL || iData < iHead->_iData) 
	{
		newNode->_next = iHead;
		return newNode;
	}

	LinkedList* curr = iHead;
    while (curr->_next != nullptr && curr->_next->_iData < iData)
    {
        curr = curr->_next;
    }

	newNode->_next = curr->_next;
    curr->_next = newNode;
	return iHead;
}

void DisplayLinkedList(LinkedList* iHead)
{
	LinkedList* node = iHead;
	while (NULL != node)
	{
		std::cout << node->_iData << " ";
		node = node->_next;
	}
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 10);
	head = InsertAtTheEnd(head, 20);
	head = InsertAtTheEnd(head, 30);
	DisplayLinkedList(head);
	std::cout << std::endl;
    head = InsertAtGivenKey(head, 55);
	DisplayLinkedList(head);
	return 0;
}
