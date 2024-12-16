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

LinkedList* InsertAtBegin(LinkedList* iHead, int iValue)
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
    return newNode;
}

LinkedList* InsertAtBegin1(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);

    if(iHead == nullptr) return newNode;

    LinkedList* headNext = iHead->_next;
    iHead->_next = newNode;
    newNode->_next = headNext;

    int tempData = iHead->_data;
    iHead->_data = newNode->_data;
    newNode->_data = tempData;

    return iHead;
}

int main()
{
    LinkedList* head = NULL;
    head = InsertAtBegin1(head, 1);
    head = InsertAtBegin1(head, 2);
    head = InsertAtBegin1(head, 3);
    Display(head);
}