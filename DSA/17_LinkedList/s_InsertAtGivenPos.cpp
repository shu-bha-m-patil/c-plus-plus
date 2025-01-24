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

LinkedList* InsertAtGivenPos(LinkedList* iHead, int iPos, int iValue)
{
	if(0 == iPos)
		std::cout << "Provide a valid value.";

    LinkedList* newNode = new LinkedList(iValue);
	if(iPos == 1)
	{
		newNode->_nextNode = iHead;
		iHead = newNode;
		return iHead;
	}

	int count = 1;
    LinkedList* currNode = iHead;
    while (count < (iPos - 1) && NULL != currNode)
    {
        currNode = currNode->_nextNode;
        count++;
    }

    if(NULL != currNode)
    {
        LinkedList* currNodeNext = currNode->_nextNode;
        currNode->_nextNode = newNode;
        newNode->_nextNode = currNodeNext;
    }
    else
    {
        std::cout << "Given position is more than the size of LinkedList." << std::endl;
        std::cout << "Can not insert the given value." << std::endl;
    }

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


int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 10);
	head = InsertAtTheEnd(head, 20);
	head = InsertAtTheEnd(head, 30);
	DisplayLinkedList(head);
    std::cout << std::endl;
    head = InsertAtGivenPos(head, 0, 25);
	DisplayLinkedList(head);

	return 0;
}
