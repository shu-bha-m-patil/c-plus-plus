#include <iostream>


int ModHash(int key)
{
    return key % size;
}

int Search(int bucket[], size_t size, int key, int (*hash)(int key))
{
    int index = hash(key);
    if (bucket[index] == key)
        return index;
    return -1;
}

const size_t size = 5;

int main()
{
    const size_t size = 5;
    int bucket[size] = { 5,71,62,28,19 };
    int result = Search(bucket, size, 19, ModHash);
    result = Search(bucket, size, 42, ModHash);
    return 0;
}

/*
Components of a hash table include: the hash function and the bucket.
*/