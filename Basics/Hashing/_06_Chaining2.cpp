#include <iostream>
#include <list>
#include <vector>

struct HashEntry
{
    int key;
    std::list<int> bucket;
    HashEntry() : key(-1) {}
};

const size_t size = 5;  

/* Hash Function */
int ModHash(int key)
{
    return key % size;
}

int Store(std::vector<HashEntry>& storage, int key, int(*hash)(int))
{
    int index = hash(key);
    if (storage[index].key == -1)
    {
        storage[index].key = key;
        return true;
    }
    storage[index].bucket.push_front(key);
    return true;
}

int main()
{
    std::vector<HashEntry>storage(size);
    int result = Store(storage, 5, ModHash);
    result = Store(storage, 25, ModHash);
    return 0;
}
