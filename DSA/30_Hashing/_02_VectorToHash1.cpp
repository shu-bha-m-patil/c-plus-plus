#include <iostream>

int Search(int arr[], size_t size, int value)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    const size_t size = 5;
    int arr[size] = { 5,71,62,28,19 };
    int result = Search(arr, size, 19);
    result = Search(arr, size, 42);
    return 0;
}

/*
There is ont direct relationship between an element's index and its value,
so finding a specific value requires axamining each element individually.
*/