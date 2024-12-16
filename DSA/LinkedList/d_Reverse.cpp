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
    while(curr != NULL)
    {
        std::cout << curr->_data << " ";
        curr = curr->_next;
    }
    std::cout << std::endl;
}

LinkedList* InsertAtEnd(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);
    if(iHead == NULL)
    {
        iHead = newNode;
        return iHead;
    }

    LinkedList* curr = iHead;
    while (curr->_next != NULL)
    {
        curr = curr->_next;
    }
    
    
    curr->_next = newNode;
    newNode->_prev = curr;
    return iHead;
}

LinkedList* Reverse(LinkedList* iHead)
{
    if(iHead == NULL || iHead->_next == NULL) return iHead;

    LinkedList* prevNode = NULL;
    LinkedList* curr = iHead;
    while (curr != NULL)
    {
        prevNode = curr->_prev;
        curr->_prev = curr->_next;
        curr->_next = prevNode;
        curr = curr->_prev;
    }
    return prevNode->_prev;    
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
    head = Reverse(head);
    Display(head);
}