#include <iostream>

const size_t size = 5;

/* Hash Function */
int ModHash(int key)
{
    return key% size;
}

int Store(int arr[], size_t size, int key, int (*hash)(int))
{
    int index = hash(key);
    if (arr[index] == -1)
    {
        arr[index] = key;
        return true;
    }
    return false;
}

int main()
{
    int arr[size] = { -1, 71, 62, 28, 19 };
    int result = Store(arr, size, 5, ModHash);
    result = Store(arr, size, 25, ModHash);
    return 0;
}

/*
A collision occurs when you attempt to insert a new record into a hash table, 
but the index calculated by the hash function is already occupied by a previously stored record.
This situation arises due to the limited size of the hash table and the nature of the hash function, 
which may produce the same index for different keys (also known as hash collisions).
*/