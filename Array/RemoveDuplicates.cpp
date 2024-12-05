#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

// Remove element logic
void RemoveElement(int* arr, int& size, int index)
{
    for (size_t i = index; i < size - 1; i++)
    {
		arr[i] = arr[i + 1];
    }
	size--;
}

void RemoveDuplicates(int* arr, int& size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j)
		{
			if (arr[i] == arr[j])
				RemoveElement(arr, size, j);
			else
				++j;
		}
	}
	
}

// create new array of distinct element if array is sorted
int* RemoveDuplicateElement(int* arr, int& size)
{
	int* ptr = new int[size]; 
	ptr[0] = arr[0];
	int distPos = 0;
	int modArrSize = size;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			distPos++;
			ptr[distPos] = arr[i];
		}
		else
			modArrSize--;
	}
	size = modArrSize;
	return ptr;
}

// without using other array
void RemoveDuplicatesElement(int* arr, int& size, int next = 5)
{
	int distPos = 0;
	int modArrSize = size;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			distPos++;
			arr[distPos] = arr[i];
		}
		else
			modArrSize--;
	}
	size = modArrSize;
}

int main()
{
	int arr[10] = { 1,2,2,2,2,2,3};

	int size = 7;
	Display(arr, size);
	std::cout << std::endl;
	int* val = RemoveDuplicateElement(arr, size);
	Display(val, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
