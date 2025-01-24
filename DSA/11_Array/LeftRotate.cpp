#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}


void LeftRotate(int* arr, int& size, int pos)
{
	// For pos greater than size
	pos = pos % size;


	int* tempArr = new int[pos];
	int index = size - pos;
	for (size_t i = 0; i < pos; i++)
	{
		tempArr[i] = arr[index];
		arr[index] = arr[i];
		index++;
	}

    for (size_t i = pos; i < size - pos; i++)
    {
        arr[i - pos] = arr[i];
    }

	index = size - 2 * pos;
	for (size_t i = 0; i < pos; i++)
	{
		arr[index] = tempArr[i];
		index++;
	}

	delete[] tempArr;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9};

	int size = 9;
	Display(arr, size);
	std::cout << std::endl;
	int pos = 12;
	LeftRotate(arr, size, pos);
	Display(arr, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
