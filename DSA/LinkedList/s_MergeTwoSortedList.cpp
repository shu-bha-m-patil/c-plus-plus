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

LinkedList* MergeTwoSortedList(LinkedList* head1, LinkedList* head2)
{
	LinkedList* curr1 = head1;
	LinkedList* curr2 = head2;

	LinkedList* head = nullptr;
	LinkedList* tail = nullptr;
	if(head1->_iData < head2->_iData)
	{
		head = head1;
		tail = head1;
		curr1 = curr1->_next;
	}
	else
	{
		head = head2;
		tail = head2;
		curr2 = curr2->_next;
	}

	while (curr1 || curr2)
	{
		if(curr1 == nullptr)
		{
			tail->_next = curr2;
			break;
		}

		if(curr2 == nullptr)
		{
			tail->_next = curr1;
			break;
		}

		if(curr1->_iData < curr2->_iData)
		{
			tail->_next = curr1;
			curr1 = curr1->_next;
		}
		else
		{
			tail->_next = curr2;
			curr2 = curr2->_next;
		}
		tail = tail->_next;
	}
	return head;
}

int main()
{
    // 1. Using unordered_set
    // 2. Last linked list size - small liked list stize, travelling same speed
	LinkedList* head1 = NULL;
	head1 = InsertAtTheEnd(head1, 1);
	head1 = InsertAtTheEnd(head1, 3);
	head1 = InsertAtTheEnd(head1, 5);
	head1 = InsertAtTheEnd(head1, 7);
	head1 = InsertAtTheEnd(head1, 9);
	Display(head1);
	
	LinkedList* head2 = NULL;
	head2 = InsertAtTheEnd(head2, 2);
	head2 = InsertAtTheEnd(head2, 4);
	head2 = InsertAtTheEnd(head2, 6);
	head2 = InsertAtTheEnd(head2, 8);
	Display(head2);

	LinkedList* head = MergeTwoSortedList(head1, head2);
	Display(head);

	return 0;
}

