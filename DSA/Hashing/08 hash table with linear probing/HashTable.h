#pragma once

#include <vector>

struct HashItem {
	int key;
	bool occupied;
	bool deleted;
public:
	HashItem() : key(0), occupied(false), deleted(false) {}
	HashItem(int key, bool occupied) : key(key), occupied(occupied), deleted(false) {}
};

class HashTable {
public:
	HashTable(size_t initial_capacity = 5, double max_load_factor = 0.75);
public:
	std::pair<int, bool> Insert(int key);
	bool Remove(int key);
public:
	std::pair<int, bool> Find(int key);
private:
	size_t Hash(int key) const;
	void Rehash();
private:
	std::vector<HashItem> m_storage;
	double m_maxLoadFactor;
	size_t m_size;
	size_t m_capacity;
};