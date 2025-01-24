#include <iostream>
#include <unordered_set>

struct LinkedList
{
	int _iData;
	LinkedList* _next;
    bool bVisited;
	LinkedList(int value)
	{
        bVisited = false;
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

LinkedList* CreateLoop(LinkedList* iHead)
{
    LinkedList* prevNode = nullptr;
	LinkedList* curr = iHead;
	while (curr->_next != nullptr)
	{
        prevNode = curr;
		curr = curr->_next;
	}
    curr->_next = prevNode;
    std::cout << std::endl;
    return iHead;
}

bool IsLoopPresent(LinkedList* iHead)
{
    LinkedList* curr = iHead;
    while (curr != nullptr)
    {
        if(curr->bVisited)
            return true;
        
        curr->bVisited = true;
        curr = curr->_next;
    }
    return false;
}

bool IsLoopPresent1(LinkedList* iHead)
{
    std::unordered_set <LinkedList*> set;
    LinkedList* curr = iHead;
    while (curr != nullptr)
    {
        if(set.find(curr) == set.end())
            set.insert(curr);
        else
            return true;
        curr = curr->_next;
    }
    return false;
}

bool IsLoopPresent2(LinkedList* iHead)
{
    LinkedList* fast = iHead;
    LinkedList* slow = iHead;
    while (fast != nullptr && fast->_next != nullptr)
    {
        fast = fast->_next->_next;
        slow = slow->_next;

        if(fast == slow)
            return true;
    }
    return false;
}

int main()
{
	LinkedList* head = NULL;
	head = InsertAtTheEnd(head, 1);
	head = InsertAtTheEnd(head, 2);
	head = InsertAtTheEnd(head, 3);
	Display(head);

    head = CreateLoop(head);

    if(IsLoopPresent2(head))
        std::cout << "The loop is present in given list" << std::endl;
    else
        std::cout << "The loop is not present in given list" << std::endl;

	return 0;
}
