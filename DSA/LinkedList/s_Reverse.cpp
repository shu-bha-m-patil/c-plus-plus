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

LinkedList* SwappingPointerReverse(LinkedList* iHead)
{
    if(iHead == nullptr || iHead->_next == nullptr) return iHead;

	LinkedList* curr = iHead;
	LinkedList* prev = nullptr;
	LinkedList* currNext = nullptr;
	while (curr != nullptr)
	{
        currNext = curr->_next;
		curr->_next = prev;
        prev = curr;
        curr = currNext;
	}
    return prev;
}

LinkedList* TailReverseRecurcive(LinkedList* curr, LinkedList*& ohead)
{
    if(curr->_next == nullptr)
    {
		ohead = curr;
        return curr;
    }

	LinkedList* tail = TailReverseRecurcive(curr->_next, ohead);
	tail->_next = curr;
    return curr;
}


LinkedList* FrontReverseRecursion(LinkedList* ihead, LinkedList*& iPrev)
{
	if(ihead == nullptr) 
		return iPrev;

	LinkedList* nextNode = ihead->_next;
	ihead->_next = iPrev;
    return FrontReverseRecursion(nextNode, ihead);;
}


int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 5);
	DisplayLinkedList(head);

	head = SwappingPointerReverse(head);
	DisplayLinkedList(head);

    LinkedList* newHead = nullptr;
	head = TailReverseRecurcive(head, newHead);
	head->_next = nullptr;
	DisplayLinkedList(newHead);

	head = nullptr;
	head = FrontReverseRecursion(newHead, head);
	DisplayLinkedList(head);

	return 0;
}
