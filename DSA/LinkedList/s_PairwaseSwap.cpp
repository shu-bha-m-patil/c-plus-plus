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

LinkedList* SwapPairWise(LinkedList* iHead)
{
    LinkedList* curr = iHead;
    LinkedList* prev = nullptr;
    LinkedList* next = nullptr;
    LinkedList* newHead = nullptr;
    if(curr->_next != nullptr)
        newHead = curr->_next;

    while (curr != nullptr && curr->_next != nullptr)
    {
        next = curr->_next;
        curr->_next = curr->_next->_next;
        next->_next = curr;
        if(prev)
            prev->_next = next;
        prev = curr;
        curr = curr->_next;
    }
    return newHead;
}


int main()
{
    // 1. Using unordered_set
    // 2. Last linked list size - small liked list stize, travelling same speed
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 5);
	Display(head);
    head = SwapPairWise(head);
	Display(head);
	return 0;
}

