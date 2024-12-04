#include <iostream>

bool IsDecrementing(int* arr, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1]) 
			return false;
	}
	return true;
}

bool IsIncrementing(int* arr, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1]) 
			return false;
	}
	return true;
}

bool IsArraySorted(int* arr, int size)
{
	return IsIncrementing(arr, size) || IsDecrementing(arr, size);
}

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

int main()
{
	int arr[10] = { 9,8,7 };

	Display(arr, 3);
	std::cout << std::endl;
	std::cout << "The array is " << IsArraySorted(arr, 3) << std::endl;
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
