#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}


void PrintMaxProfit(int* arr, int& size)
{
	if (size == 1)
		std::cout << "Max profit is " << arr[0];

	int profit = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i - 1] < arr[i])
			profit = profit + (arr[i] - arr[i - 1]);
	}

	std::cout << "Max profit is " << profit;
}

int main()
{
	int arr[10] = {1,5,3,1,2,8};

	int size = 6;
	Display(arr, size);
	std::cout << std::endl;
	PrintMaxProfit(arr, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
