#include <iostream>

struct LinkedList
{
    int _data;
    LinkedList* _prev;
    LinkedList* _next;
    LinkedList(int iValue)
    {
        _data = iValue;
        _prev = _next = NULL;
    }
};

void Display(LinkedList* iHead)
{
    LinkedList* curr = iHead;
    if(curr == NULL) return;
    do
    {
        std::cout << curr->_data << " ";
        curr = curr->_next;
    }while (curr != iHead);
    std::cout << std::endl;
}

LinkedList* InsertAtEnd(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);
    if(iHead == NULL)
    {
        newNode->_next = newNode;
        newNode->_prev = newNode;
        iHead = newNode;
        return iHead;
    }

    LinkedList* tail = iHead->_prev;
    tail->_next = newNode;
    newNode->_prev = tail;

    newNode->_next = iHead;
    iHead->_prev = newNode;

    return iHead;
}

LinkedList* DeleteHead(LinkedList* iHead)
{
	return iHead->_next;
		
	if(iHead == NULL) return nullptr;
	if(iHead->_next == NULL) 
	{
		delete iHead; iHead = nullptr;
		return nullptr;
	}

	LinkedList* headNext = iHead->_next;
	iHead->_next->_prev = NULL;
	delete iHead; iHead = nullptr;
	return headNext;
}

int main()
{
    LinkedList* head = NULL;
    head = InsertAtEnd(head, 1);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 4);
    head = InsertAtEnd(head, 5);
    Display(head);
    head = DeleteHead(head);
    Display(head);
}