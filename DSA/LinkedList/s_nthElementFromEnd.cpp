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

int CountLinkedListNodes(LinkedList* iHead)
{
    int count = 0;
	LinkedList* node = iHead;
	while (NULL != node)
	{
        ++count;
		node = node->_next;
	}
    return count;
}

void PrintNthelementFromLast(LinkedList* iHead, int KthElement)
{
    int count = CountLinkedListNodes(iHead);
    std::cout << "The totat nodes are " << count << std::endl;

    if(KthElement > count) return;

    int fromStart = count - KthElement + 1;
    int startCount = 1;
    LinkedList* curr = iHead;
    while (startCount != fromStart)
    {
        curr = curr->_next;
        ++startCount;
    }
    std::cout << "The " << KthElement << "th element from last is " << curr->_iData << std::endl;
}

void PrintNthelementFromLast1(LinkedList* iHead, int KthElement)
{
	int count = CountLinkedListNodes(iHead);
	if(KthElement > count)
		return;

	int currCount = 0;
	LinkedList* second = iHead;
	LinkedList* first = iHead;
	while (currCount != KthElement)
	{
		second = second->_next;
		++currCount;
	}
	
	while (second != nullptr)
	{
		second = second->_next;
		first = first->_next;
	}
	

    std::cout << "The " << KthElement << "th element from last is " << first->_iData << std::endl;
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
    PrintNthelementFromLast1(head, 5);
	std::cout << std::endl;
	return 0;
}
