#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}


void PrintMaxProfit(int* arr, int& size)
{
	int amountRainTrap = 0;
	int leftPollIndex = 0;
	int amountOfWaterToRemove = 0;
	for (size_t i = 1; i < size - 1; i++)
	{
		if ((i + 1) == (size - 1) && (arr[leftPollIndex] > arr[i + 1]) && (arr[i] < arr[i + 1]))
		{
			amountRainTrap = amountRainTrap + (arr[leftPollIndex] - arr[i]);
			amountOfWaterToRemove = (i - leftPollIndex) * (arr[leftPollIndex] - arr[i + 1]);
			amountRainTrap = amountRainTrap - amountOfWaterToRemove;
			break;
        }

        if ((arr[i] > arr[i + 1]) && (arr[leftPollIndex] > arr[i]))
        {
            amountOfWaterToRemove = ((i - leftPollIndex) - 1) * (arr[leftPollIndex] - arr[i]);
            amountRainTrap = amountRainTrap - amountOfWaterToRemove;
            leftPollIndex = i;
        }

        if (arr[leftPollIndex] < arr[i])
            arr[leftPollIndex] = i;
		else
		{
			amountRainTrap = amountRainTrap + (arr[leftPollIndex] - arr[i]);
		}
	}

	std::cout << "Total amount of rain trap is " << amountRainTrap;
}

int main()
{
	//int arr[6] = {6,1,2,5,4,3};
	int arr[6] = {3,2,1};

	int size = 6;
	Display(arr, size);
	std::cout << std::endl;
	PrintMaxProfit(arr, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
