#include <iostream>

struct LinkedList
{
    int _iData;
    LinkedList* _next;
    LinkedList(int value)
    {
        _iData = value;
        _next = nullptr;
    }
};

LinkedList* InsertAtTheEnd(LinkedList* iHead, int iValue)
{
    LinkedList* newNode = new LinkedList(iValue);
    if (iHead == nullptr)
    {
        return newNode;
    }

    LinkedList* tempNode = iHead;
    while (tempNode->_next != nullptr)
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

LinkedList* SegregateEvenOdd(LinkedList* iHead)
{
    if (iHead == nullptr) return nullptr; // Handle empty list

    LinkedList *evenHead = nullptr, *evenTail = nullptr;
    LinkedList *oddHead = nullptr, *oddTail = nullptr;

    LinkedList* curr = iHead;
    while (curr != nullptr)
    {
        if (curr->_iData % 2 == 0) // Even node
        {
            if (evenHead == nullptr)
            {
                evenHead = evenTail = curr; // Initialize even list
            }
            else
            {
                evenTail->_next = curr;
                evenTail = curr;
            }
        }
        else // Odd node
        {
            if (oddHead == nullptr)
            {
                oddHead = oddTail = curr; // Initialize odd list
            }
            else
            {
                oddTail->_next = curr;
                oddTail = curr;
            }
        }
        curr = curr->_next;
    }

    // Connect even list to odd list
    if (evenTail != nullptr)
    {
        evenTail->_next = oddHead;
    }

    // Terminate the odd list
    if (oddTail != nullptr)
    {
        oddTail->_next = nullptr;
    }

    // Return new head (evenHead if exists, otherwise oddHead)
    return (evenHead != nullptr) ? evenHead : oddHead;
}

int main()
{
    LinkedList* head = nullptr;
    head = InsertAtTheEnd(head, 1);
    head = InsertAtTheEnd(head, 2);
    head = InsertAtTheEnd(head, 3);
    head = InsertAtTheEnd(head, 4);
    head = InsertAtTheEnd(head, 5);
    head = InsertAtTheEnd(head, 6);
    Display(head);

    head = SegregateEvenOdd(head);
    Display(head);

    return 0;
}
