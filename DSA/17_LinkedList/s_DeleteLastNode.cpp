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

LinkedList* DeleteLastNode(LinkedList* iHead)
{
    if(iHead == NULL) return NULL;

    if(iHead->_nextNode == NULL)
    {
        delete iHead; return NULL;
    }

    LinkedList* currNode = iHead;
    while (currNode->_nextNode->_nextNode != NULL)
    {
        currNode = currNode->_nextNode;
    }
    
    delete currNode->_nextNode;
    currNode->_nextNode = NULL;

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
    head = DeleteLastNode(head);
	DisplayLinkedList(head);
}