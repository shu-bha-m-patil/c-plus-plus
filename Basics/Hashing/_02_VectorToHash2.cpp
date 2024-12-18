#include <iostream>

int Search(int arr[], size_t size, int value)
{
    int index = value % size;
    if (arr[index] == value)
        return index;
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
In a hash table, a hash function extablishesh a relationship between each key and a specific index, 
allowing for direct access to values.
*/