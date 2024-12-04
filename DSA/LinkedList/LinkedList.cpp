#include <iostream>

struct LinkedList
{
	int _iData;
	LinkedList* _nextNode;

	LinkedList(int iData);
	void BuildList(int* iArray, int iSize);
	void InsertAtNode(int iIndex);
	void DeleteAtNode(int iIndex);
};

LinkedList::LinkedList(int iData)
{
	_iData = iData;
	_nextNode = NULL;
}

void LinkedList::BuildList(int* iArray, int iSize)
{
	LinkedList* CurNode = this; if (CurNode == NULL) return;
	LinkedList* NextNode = NULL;
	for (size_t i = 0; i < iSize; i++)
	{
		if (i == iSize - 1)
			CurNode->_nextNode = NULL;
		else
		{
			NextNode = new LinkedList(iArray[i + 1]);
			CurNode->_nextNode = NextNode;
			CurNode = NextNode;
		}
	}
}

void LinkedList::InsertAtNode(int iIndex)
{
	if (this == NULL) return;
	LinkedList* currNode = this;
	LinkedList* NextNode = NULL;
	for (size_t i = 1; i < iIndex - 1; i++)
	{
		currNode = currNode->_nextNode;
	}
	LinkedList* indexNode = new LinkedList(iIndex);
	LinkedList* indexNextNode = currNode->_nextNode;
	currNode->_nextNode = indexNode;
	indexNode->_nextNode = indexNextNode;
}

void LinkedList::DeleteAtNode(int iIndex)
{
	if (this == NULL) return;
	LinkedList* currNode = this;
	LinkedList* NextNode = NULL;
	for (size_t i = 1; i < iIndex - 1; i++)
	{
		currNode = currNode->_nextNode;
	}
	LinkedList* indexNode = currNode->_nextNode;
	currNode->_nextNode = indexNode->_nextNode;
	delete indexNode; indexNode = NULL;
}

void Display(LinkedList* iListNode)
{
	std::cout << "List data is like : ";
	while (iListNode != NULL)
	{
		std::cout << iListNode->_iData << " ";
		iListNode = iListNode->_nextNode;
	}
	std::cout << std::endl;
}

int LinkedListMain()
{
	std::cout << "This is the array " << std::endl;
	int iArray[] = { 1, 3, 6, 8, 9, 11, 66, 77, 99, 101 };
	int iSize = sizeof(iArray) / sizeof(int);
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
	std::cout << std::endl;

	LinkedList* HeadNode = NULL;
	HeadNode = new LinkedList(iArray[0]);
	HeadNode->BuildList(iArray, iSize);

	Display(HeadNode);

	int iIndex = 0;
	std::cout << "Enter an element to Insert" << std::endl;
	std::cin >> iIndex;
	HeadNode->InsertAtNode(iIndex);

	Display(HeadNode);

	std::cout << "Enter an element to Delete" << std::endl;
	std::cin >> iIndex;
	HeadNode->DeleteAtNode(iIndex);

	Display(HeadNode);

	return 0;
}
