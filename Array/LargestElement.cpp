#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

void PrintLargetElement(int* arr, int size)
{
	int largeEle = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > largeEle)
		{
			largeEle = arr[i];
		}
	}
	std::cout << "The largest element is " << largeEle << std::endl;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6 };

	Display(arr, 6);
	std::cout << std::endl;
	PrintLargetElement(arr, 6);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
