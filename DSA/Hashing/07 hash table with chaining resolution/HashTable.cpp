#include "HashTable.h"

HashTable::HashTable(size_t initial_capacity, double max_load_factor)
    : m_storage(initial_capacity), m_maxLoadFactor(max_load_factor), m_size(0), m_capacity(initial_capacity)
{
}

std::pair<std::list<int>::iterator, bool> HashTable::Insert(int key)
{
    // Get access to the bucket
    size_t index = Hash(key);
    auto& chain = m_storage[index];

    // check if key exist in the hash table
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (*it == key)
        {
            return { it, false };
        }
    }

    // Key is unique, insert it into the storage
    // Note key is inserted at the front of the list
    chain.push_front(key);
    m_size++;

    if (static_cast<double>(m_size / m_capacity) > m_maxLoadFactor)
    {
        Rehash();
        return Find(key);
    }

    // Return iterator to the newly inserted key and 
    // true for successful insertion
    auto it = chain.begin();
    return { it, true };
}

bool HashTable::Remove(int key)
{
    // Get access to the bucket
    size_t index = Hash(key);
    auto& chain = m_storage[index];

    // check if key exist in the hash table
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (*it == key)
        {
            chain.erase(it); // Remove the key if found
            m_size--; // Decrease the size after removal
            return true; // Remove successful
        }
    }
    return false;
}

std::pair<std::list<int>::iterator, bool> HashTable::Find(int key)
{
    // Get access to the bucket
    size_t index = Hash(key);
    auto& chain = m_storage[index];

    // check if key exist in the hash table
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (*it == key)
        {
            return { it, true };
        }
    }

    // key desn't exist
    return { chain.end(), false};
}

size_t HashTable::Hash(int key) const
{
    return key % m_capacity;
}

void HashTable::Rehash()
{
    // Double the capacity for the new hash table
    m_capacity *= 2;
    std::vector <std::list<int>> new_storage(m_capacity);

    for (auto& chain : m_storage)
    {
        for (auto key : chain)
        {
            size_t index = Hash(key);
            new_storage[index].push_front(key);
        }
    }

    m_storage.swap(new_storage);
}
