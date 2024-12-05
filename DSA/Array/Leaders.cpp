#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

int* GetLeaders(int* arr, int &size)
{
	int* LeadersArr = new int[size];
	for (size_t i = 0; i < size; i++)
		LeadersArr[i] = INT_MAX;

	int smallestLeaderIndex = 0;
	LeadersArr[smallestLeaderIndex] = arr[0];
	smallestLeaderIndex++;
	for (size_t i = 1; i < size; i++)
	{
		if (LeadersArr[smallestLeaderIndex - 1] > arr[i])
		{
			LeadersArr[smallestLeaderIndex] = arr[i];
			smallestLeaderIndex++;
		}
		else
		{
			while (LeadersArr[smallestLeaderIndex - 1] <= arr[i] && smallestLeaderIndex > 0)
			{
				smallestLeaderIndex--;
			}
			LeadersArr[smallestLeaderIndex] = arr[i];
			++smallestLeaderIndex;
		}
	}

	size = smallestLeaderIndex;
	return LeadersArr;
}

int* GetLeadersLeftToRight(int* arr, int &size)
{
	int* LeadersArr = new int[size];
	for (size_t i = 0; i < size; i++)
		LeadersArr[i] = 0;
	int currLeaderIndex = 0;
	LeadersArr[currLeaderIndex] = arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		if (arr[i] > LeadersArr[currLeaderIndex])
		{
			currLeaderIndex = currLeaderIndex + 1;
			LeadersArr[currLeaderIndex] = arr[i];
		}
	}
	size = currLeaderIndex + 1;
	return LeadersArr;
}

int main()
{
	int arr[10] = { 7,10,4,10,6,5,2};

	int size = 7;
	Display(arr, size);
	std::cout << std::endl;
	int pos = 12;
	int* leaders = GetLeadersLeftToRight(arr, size);
	Display(leaders, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
