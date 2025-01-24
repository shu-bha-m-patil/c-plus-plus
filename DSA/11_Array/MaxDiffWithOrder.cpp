#include <iostream>

void Display(int* arr, int smallestIndex, int maxIndex, int diff)
{
	std::cout << "The smallest value : " << arr[smallestIndex] << std::endl;
	std::cout << "The max value : " << arr[maxIndex] << std::endl;
	std::cout << "The diff : " << diff << std::endl;
}

void DisplayArr(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

void MaxDiffWithOrder(int* arr, int& size, int& diffSmallestIndex, int& diffMaxIndex, int& diff)
{
	diff = INT_MIN;
	int smallestIndex = 0;
	for (size_t i = 1; i < size; i++)
	{
		if(arr[i] - arr[smallestIndex] > diff)
		{
			diff = arr[i] - arr[smallestIndex];
			diffSmallestIndex = smallestIndex;
			diffMaxIndex = i;
		}

		if (arr[smallestIndex] > arr[i])
		{
			smallestIndex = i;
		}
	}
}

int main()
{
	int arr[10] = { 6,3,10,1,4,20,5 };
	//int arr[10] = { 30,10,8,2,1};

	int size = 5;
	DisplayArr(arr, size);
	std::cout << std::endl;

	int smallestIndex = 0;
	int maxIndex = 0;
	int diff = INT_MIN;
	MaxDiffWithOrder(arr, size, smallestIndex, maxIndex, diff);
	Display(arr, smallestIndex, maxIndex, diff);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
