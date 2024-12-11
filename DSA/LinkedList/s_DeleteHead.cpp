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

void DisplayLinkedList(LinkedList* iHead)
{
    LinkedList* currNode = iHead;
    while (NULL != currNode)
    {
        std::cout << currNode->_iData << " ";
        currNode = currNode->_nextNode;
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

LinkedList* DeleteHead(LinkedList* iHead)
{
    LinkedList* newHead = iHead->_nextNode;
    delete iHead; iHead = NULL;
    return newHead;
}


int main()
{
    LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 10);
	head = InsertAtTheEnd(head, 20);
	head = InsertAtTheEnd(head, 30);
	DisplayLinkedList(head);
    std::cout << std::endl;
    head = DeleteHead(head);
	DisplayLinkedList(head);
}