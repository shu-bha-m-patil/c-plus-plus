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

void CreateLoop(LinkedList* iHead, LinkedList* iHead2)
{
    LinkedList* dataThreeNode = nullptr;
	LinkedList* curr = iHead;
	while (curr->_iData != 3)
	{
		curr = curr->_next;
	}
    dataThreeNode = curr;

	curr = iHead2;
	while(curr->_next != nullptr)
	{
		curr = curr->_next;
	};

    curr->_next = dataThreeNode;
    std::cout << std::endl;
}

void PrintIntersectionNode(LinkedList* iHead, LinkedList* iHead2)
{
    int count = 0;
	LinkedList* curr = iHead;
	while (curr != nullptr)
	{
		++count;
		curr = curr->_next;
	}
	
    int count2 = 0;
	curr = iHead2;
	while (curr != nullptr)
	{
		++count2;
		curr = curr->_next;
	}
	
	LinkedList* curr2 = nullptr;
	int diff = 0;
	if(count > count2)
	{
		curr = iHead;
		diff = count - count2;
		while (diff != 0 && curr != nullptr)
		{
			curr = curr->_next;
			diff--;
		}
		curr2 = iHead2;
	}
	else	
	{
		curr = iHead2;
		diff = count2 - count;
		while (diff != 0 && curr != nullptr)
		{
			curr = curr->_next;
			diff--;
		}
		curr2 = iHead;
	}

	while (curr != nullptr)
	{
		if(curr == curr2)
		{
			std::cout << "The commond meeting point is " << curr->_iData << std::endl;
			return;
		}
		
		curr = curr->_next;
		curr2 = curr2->_next;
	}
	
	if(curr)
		std::cout << "No common meeting point " << curr->_iData << std::endl;
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

	LinkedList* head2 = NULL;
	head2 = InsertAtTheEnd(head2, 11);
	head2 = InsertAtTheEnd(head2, 12);
	head2 = InsertAtTheEnd(head2, 13);
	head2 = InsertAtTheEnd(head2, 14);
	head2 = InsertAtTheEnd(head2, 15);
	head2 = InsertAtTheEnd(head2, 16);
    CreateLoop(head, head2);
	Display(head2);


    PrintIntersectionNode(head, head2);

	return 0;
}
