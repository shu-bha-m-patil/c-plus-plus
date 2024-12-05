#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

void Delete(int* arr, int size, int val)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == val) 
		{
			for (size_t j = i; j < size - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			break;
		}
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6 };

	Display(arr, 6);
	std::cout << std::endl;
	Delete(arr, 6, 4);
	Display(arr, 5);


	int temp = 0;
	std::cin >> temp;

	return 0;
}
