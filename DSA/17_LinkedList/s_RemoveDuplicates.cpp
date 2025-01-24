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

void DisplayLinkedList(LinkedList* iHead)
{
	LinkedList* node = iHead;
	while (NULL != node)
	{
		std::cout << node->_iData << " ";
		node = node->_next;
	}
    std::cout << std::endl;
}

void RemoveDuplicates(LinkedList* iHead)
{
    if(iHead == nullptr || iHead->_next == nullptr) return;

    LinkedList* curr = iHead;
    while (curr->_next != nullptr)
    {
        if(curr->_iData == curr->_next->_iData)
        {
            LinkedList* tempNode = curr->_next;
            curr->_next = curr->_next->_next;
            delete tempNode;
        }
        else
            curr = curr->_next;
    }
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 4);
	DisplayLinkedList(head);
    RemoveDuplicates(head);
	DisplayLinkedList(head);
	return 0;
}
