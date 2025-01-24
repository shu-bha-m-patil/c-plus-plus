#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

// O (n^2)
void MoveZerosToEnd(int* arr, int& size)
{
	int zeroIndex = -1;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] == 0)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (arr[j] != 0)
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					break;
				}
			}
        }
    }
}

// O (n)
void MoveZerosToEndOmegaN(int* arr, int& size)
{
	int intCout = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			int temp = arr[i];
			arr[i] = arr[intCout];
			arr[intCout] = temp;
			intCout++;
		}
	}
}

int main()
{
	int arr[10] = { 1,2,0,0,2,0,3};

	int size = 7;
	Display(arr, size);
	std::cout << std::endl;
	MoveZerosToEndOmegaN(arr, size);
	Display(arr, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
