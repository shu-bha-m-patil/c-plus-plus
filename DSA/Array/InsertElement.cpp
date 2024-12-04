#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

void Insert(int* arr, int size, int pos, int val)
{
	if (pos >= size) return;
	for (size_t i = size - 1; i >= pos - 1; i--)
	{
		arr[i + 1] = arr[i];
	}

	arr[pos - 1] = val;
}

int main()
{
	int arr[10] = { 1,3,4,5,6 };

	Display(arr, 5);
	std::cout << std::endl;
	Insert(arr, 5, 2, 2);
	Display(arr, 6);


	int temp = 0;
	std::cin >> temp;

	return 0;
}
