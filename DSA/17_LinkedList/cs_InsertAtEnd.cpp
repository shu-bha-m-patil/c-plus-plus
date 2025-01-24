#include <iostream>

struct LinkedList
{
    int _data;
    LinkedList* _next;
    LinkedList(int iValue)
    {
        _data = iValue;
        _next = this;
    }
};

void Display(LinkedList* iHead)
{
    LinkedList* curr = iHead;
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

    if(iHead == nullptr) return newNode;

    LinkedList* curr = iHead;
    while (curr->_next != iHead)
    {
        curr = curr->_next;
    };
    
    curr->_next = newNode;
    newNode->_next = iHead;
    return iHead;
}

LinkedList* InsertAtEnd1(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);

    if(iHead == nullptr) return newNode;

    if(iHead->_next == nullptr)
    {
        iHead->_next = newNode;
        return iHead;
    }

    newNode->_next = iHead->_next;
    iHead->_next = newNode;

    int temp = iHead->_data;
    iHead->_data = newNode->_data;
    newNode->_data = temp;
    return newNode;
}

int main()
{
    LinkedList* head = NULL;
    head = InsertAtEnd1(head, 1);
    head = InsertAtEnd1(head, 2);
    head = InsertAtEnd1(head, 3);
    head = InsertAtEnd1(head, 4);
    head = InsertAtEnd1(head, 5);
    Display(head);
}