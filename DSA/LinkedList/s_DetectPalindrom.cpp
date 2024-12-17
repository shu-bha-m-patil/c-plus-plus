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

LinkedList* ReverseList(LinkedList* head, LinkedList* prev)
{
    if(head == nullptr)
        return prev;
    LinkedList* headNext = head->_next;
    head->_next = prev;
    return ReverseList(headNext, head);
}

LinkedList* IsPalindrom(LinkedList* head)
{
    bool isPalindrom = true;
    LinkedList* fast = head;
    LinkedList* slow = head;
    while (fast && fast->_next && fast->_next->_next)
    {
        slow = slow->_next;
        fast = fast->_next->_next;
    }
	LinkedList* revrse = ReverseList(slow->_next, nullptr);
    LinkedList* start = head;
    while (revrse)
    {
        if(start->_iData != revrse->_iData)
        {
            isPalindrom = false;
            break;
        }
        
        start = start->_next;
        revrse = revrse->_next;
    }
    if(isPalindrom)
        std::cout << "The list is palindrom" << std::endl;
    else
        std::cout << "The list is not palindrom" << std::endl;

	return head;
}

int main()
{
    // 1. Using unordered_set
    // 2. Last linked list size - small liked list stize, travelling same speed
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 4);
	head = InsertAtTheEnd(head, 6);
	head = InsertAtTheEnd(head, 5);
	head = InsertAtTheEnd(head, 3);
	head = InsertAtTheEnd(head, 1);
	Display(head);

	IsPalindrom(head);

	return 0;
}

