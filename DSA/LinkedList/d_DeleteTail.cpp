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
    while (curr != nullptr)
    {
        std::cout << curr->_data << " ";
        curr = curr->_next;
    };
    std::cout << std::endl;
}

LinkedList* InsertAtEnd(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);
    if(iHead == NULL) return newNode;
    
	if(iHead->_next == nullptr)
	{
		iHead->_next = newNode;
		newNode->_prev = iHead;
		return iHead;
	}

	LinkedList* curr = iHead;
	LinkedList* tail = nullptr;
	while (curr != nullptr)
	{
		tail = curr->_prev;
		curr = curr->_next;
	}
	tail = tail->_next;

    tail->_next = newNode;
    newNode->_prev = tail;
    return iHead;
}

LinkedList* DeleteTail(LinkedList* iHead)
{
	if(iHead == NULL) return nullptr;
	if(iHead->_next == NULL) 
	{
		delete iHead; iHead = nullptr;
		return nullptr;
	}

    LinkedList* curr = iHead;
    while (curr->_next != NULL)
    {
        curr = curr->_next;
    }
    curr->_prev->_next = nullptr;
    delete curr;
	return iHead;
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
    head = DeleteTail(head);
    Display(head);
}