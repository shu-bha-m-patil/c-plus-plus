#include <iostream>

#include "HashTable.h"

int main()
{
    HashTable hashTable;
    int keys[] = {15, 23, 42, 8, 4, 16, 23, 50, 12, 60, 42, 72};

    for (int key : keys)
    {
        auto result = hashTable.Insert(key);
        std::cout << key << " : " << (result.second ? "Inserted" : "Already Exist") << std::endl;
    }

    for (int key : keys)
    {
        auto result = hashTable.Find(key);
        std::cout << key << " : " << (result.second ? "Found" : "Not Found") << std::endl;
    }

    int keysToRemove[] = { 15, 42, 100 };
    for (int key : keysToRemove) {
        auto result = hashTable.Remove(key);
        std::cout << key << " : " << (result ? "Removed" : "Not Found") << std::endl;
    }
}