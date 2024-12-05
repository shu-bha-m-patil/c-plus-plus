#include <iostream>

void Display(int* iArray, int iSize)
{
	for (size_t i = 0; i < iSize; i++)
		std::cout << iArray[i] << " ";
}

void Reverse(int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int temp = arr[i];
        arr[i] = arr[(size - 1) - i];
        arr[(size - 1) - i] = temp;

        if ((i == (size - 1) - i) || ((size - 1) - i) - i == 1)
            break;
    }
}

int main()
{
	int arr[10] = { 9,8,7,10,11};

	int size = 5;
	Display(arr, size);
	std::cout << std::endl;
	Reverse(arr, size);
	Display(arr, size);
	std::cout << std::endl;

	int temp = 0;
	std::cin >> temp;

	return 0;
}
