#include <iostream>
#include <unordered_set>

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
	while (node != nullptr)
	{
		std::cout << node->_iData << " ";
		node = node->_next;
	}
    std::cout << std::endl;
}

void CreateLoop(LinkedList* iHead)
{
    LinkedList* dataThreeNode = nullptr;
	LinkedList* curr = iHead;
	while (curr->_iData != 3)
	{
		curr = curr->_next;
	}
    dataThreeNode = curr;
    while (curr->_next != nullptr)
	{
		curr = curr->_next;
	}

    curr->_next = dataThreeNode;
    std::cout << std::endl;
}

void FindMeetingNodeOfLoop(LinkedList* iHead)
{
    LinkedList* slow = iHead;
    LinkedList* fast = iHead;
    while (fast != nullptr && fast->_next != nullptr)
    {
        fast = fast->_next->_next;
        slow = slow->_next;

        if(slow == fast)
        {
            std::cout << "The meeting node is " << slow->_iData << std::endl;
            break;
        }
    }
}

void RemoveLoop(LinkedList* iHead)
{
    LinkedList* fast = iHead;
    LinkedList* slow = iHead;
    while (fast != nullptr && fast->_next != nullptr)
    {
        fast = fast->_next->_next;
        slow = slow->_next;

        if(fast == slow)
            break;
    }

    while (slow->_next != nullptr && fast->_next != nullptr)
    {
        slow = slow->_next;
        fast = fast->_next;
        if(slow->_next == fast->_next)
        {
            std::cout << "The intersection node is " << slow->_next->_iData << std::endl;
            break;
        }
    }
    fast->_next = nullptr;
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
	Display(head);

    CreateLoop(head);
    FindMeetingNodeOfLoop(head);
    RemoveLoop(head);
	Display(head);

	return 0;
}
