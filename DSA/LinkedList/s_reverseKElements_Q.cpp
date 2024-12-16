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

LinkedList* ReverseKElements(LinkedList* iHead, int k)
{
    LinkedList* curr = iHead;
    LinkedList* prev = nullptr;
    LinkedList* next = nullptr;
    int count = 0;

    // Reverse first `k` nodes
    while (curr != nullptr && count < k)
    {
        next = curr->_next;  // Save the next node
        curr->_next = prev;  // Reverse the link
        prev = curr;         // Move `prev` to the current node
        curr = next;         // Move to the next node
        count++;
    }

    // `iHead` now becomes the tail of this reversed group.
    // Connect the remaining list after reversing.
    if (next != nullptr)
    {
        iHead->_next = ReverseKElements(next, k);
    }

    // Return the new head of the reversed list
    return prev;
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
	DisplayLinkedList(head);
    head = ReverseKElements(head, 3);
	DisplayLinkedList(head);
	return 0;
}
