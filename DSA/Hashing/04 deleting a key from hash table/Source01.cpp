#include <iostream>

int ModHash(int key);
int Search(int bucket[], size_t size, int key, int (*hash)(int key));
bool DeleteKey(int bucket[], size_t size, int key, int (*hash)(int key));

const size_t size = 5;

int main()
{
    const size_t size = 5;
    int bucket[size] = { 5,71,62,28,19 };
    int result = Search(bucket, size, 19, ModHash);
    result = DeleteKey(bucket, size, 19, ModHash);
    result = Search(bucket, size, 19, ModHash);
    return 0;
}

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

bool DeleteKey(int bucket[], size_t size, int key, int (*hash)(int key))
{
    int index = hash(key);
    if (bucket[index] == key)
    {
        bucket[index] = -1;
        return true;
    }
    return -1;
}

/*
Components of a hash table include: the hash function and the bucket.
*/