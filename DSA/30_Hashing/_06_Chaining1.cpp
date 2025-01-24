#include <iostream>
#include <list>
#include <vector>

/* Hash Function */
int ModHash(int key)
{
    return key % size;
}

int Store(std::vector<std::list<int>>& storage, int key, int(*hash)(int))
{
    int index = hash(key);
    storage[index].push_front(key);
    return true;
}

const size_t size = 5;  

int main()
{
    std::vector<std::list<int>>storage(size);
    int result = Store(storage, 5, ModHash);
    result = Store(storage, 25, ModHash);
    return 0;
}
