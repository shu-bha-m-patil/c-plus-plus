#pragma once
#include <list>
#include <vector>
class HashTable
{
public:
    HashTable(size_t initial_capacity = 5, double max_load_factor = 0.75);
public:
    std::pair<std::list<int>::iterator, bool> Insert(int key);
    bool Remove(int key);
public:
    std::pair<std::list<int>::iterator, bool> Find(int key);
private:
    size_t Hash(int key)const;
    void Rehash();
private:
    std::vector<std::list<int>> m_storage;
    double m_maxLoadFactor;
    size_t m_size;
    size_t m_capacity;
};

