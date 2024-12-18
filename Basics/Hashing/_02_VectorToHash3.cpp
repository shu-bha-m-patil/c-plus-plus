#include <iostream>

int Search(int bucket[], size_t size, int key)
{
    int index = key % size;
    if (bucket[index] == key)
        return index;
    return -1;
}

int main()
{
    const size_t size = 5;
    int bucket[size] = { 5,71,62,28,19 };
    int result = Search(bucket, size, 19);
    result = Search(bucket, size, 42);
    return 0;
}

/*
The variable 'value' is replaced with the more formal term 'key'
The array 'arr' is replaced with the more formal term 'bucket'.
*/