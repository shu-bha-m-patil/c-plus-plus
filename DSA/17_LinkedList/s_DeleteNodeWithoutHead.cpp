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

void Display(LinkedList* iHead)
{
	LinkedList* node = iHead;
	while (NULL != node)
	{
		std::cout << node->_iData << " ";
		node = node->_next;
	}
    std::cout << std::endl;
}

void DeleteNode(LinkedList* iNode)
{
    if(iNode->_next == nullptr)
    {
        delete iNode;
        iNode = nullptr;
    }

    int tempData = iNode->_iData;
    iNode->_iData = iNode->_next->_iData;
    iNode->_next->_iData = tempData;

    LinkedList* tempNode = iNode->_next;
    iNode->_next = iNode->_next->_next;

    delete tempNode; tempNode = nullptr;
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 5);
	head = InsertAtTheEnd(head, 6);
	head = InsertAtTheEnd(head, 7);
	head = InsertAtTheEnd(head, 8);
	Display(head);

    LinkedList* curr = head;
    while(curr->_iData != 3)
    {
        curr = curr->_next;
    }
    DeleteNode(curr);

	Display(head);
	return 0;
}
