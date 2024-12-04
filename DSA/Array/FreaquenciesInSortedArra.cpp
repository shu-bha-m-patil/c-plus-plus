#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}


void PrintFrequencies(int* arr, int& size)
{
	std::cout << "The frequencies are as below" << std::endl;
	int count = 1;

	if(size == 1)
		std::cout << arr[0] << " : " << count << std::endl;

	for (size_t i = 1; i < size; i++)
	{
        if (arr[i - 1] != arr[i])
        {
            std::cout << arr[i - 1] << " : " << count << std::endl;
			count = 1;

			if(i == (size - 1))
				std::cout << arr[i] << " : " << count << std::endl;
		}
        else
		{
            count++;
			if (i == (size - 1))
				std::cout << arr[i] << " : " << count << std::endl;
		}
    }
}

int main()
{
	int arr[10] = {10,10,10,10 };

	int size = 4;
	Display(arr, size);
	std::cout << std::endl;
	PrintFrequencies(arr, size);
	
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
