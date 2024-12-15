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

int main()
{
    LinkedList* head = NULL;
    head = InsertAtEnd(head, 1);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 3);
    Display(head);
}