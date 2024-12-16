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

void PrintMidleNode(LinkedList* iHead)
{
    if(iHead == nullptr) return;

	LinkedList* fast = iHead;
	LinkedList* slow = iHead;
	while (fast != nullptr && fast->_next != nullptr)
	{
        slow = slow->_next;
		fast = fast->_next->_next;
	}

    std::cout << "The middle node is " << slow->_iData << std::endl;
}

void Display(LinkedList* iHead)
{
    LinkedList* curr = iHead;
    while (curr != nullptr)
    {
        std::cout << curr->_iData << " ";
        curr = curr->_next;
    }
    std::cout << std::endl;
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 5);
	Display(head);
	PrintMidleNode(head);
	return 0;
}
