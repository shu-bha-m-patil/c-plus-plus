#include "HashTable.h"

HashTable::HashTable(size_t initial_capacity, double max_load_factor)
	: m_storage(initial_capacity), m_maxLoadFactor(max_load_factor),
	m_size(0), m_capacity(initial_capacity) {}

std::pair<int, bool> HashTable::Insert(int key) {
	// Compute index of a key
	size_t index = Hash(key);

	// The loop will never be infinite as there will be
	// at least one unoccupied element
	while (m_storage[index].occupied) {
		if (m_storage[index].key == key) {
			if (!m_storage[index].deleted) {
				// the key is matching and not deleted
				// implies key already exist
				return { index, false };
			}
			else if (m_storage[index].deleted) {
				// the key is matching and deleted
				// so reuse the element
				break;
			}
		}
		index = (index + 1) % m_capacity; // Linear probing
	}

	// The element is either unoccupied or element is occupied and deleted
	// so insert the key at the element
	m_storage[index] = HashItem(key, true);
	m_size++;

	// Rehash if current load factor > max load factor
	if (static_cast<double>(m_size) / m_capacity > m_maxLoadFactor) {
		Rehash();
		return Find(key);
	}

	return { index, true };
}

// Marks a key as available in the hash table; returns false if the key is not found
bool HashTable::Remove(int key) {
	std::pair<int, bool> result = Find(key);

	// If result.second is true, it imples key is found
	// in that case result.first provides the index
	if (result.second) {
		m_storage[result.first].deleted = true;
		return true;
	}

	// Key not found
	return false;
}

// Find a value by key in the hash table; returns a pair with the value if found, otherwise 0 and false
std::pair<int, bool> HashTable::Find(int key) {
	size_t index = Hash(key);

	bool found = false;
	bool isOccupiedAndValid = false;

	do {
		isOccupiedAndValid = m_storage[index].occupied && !m_storage[index].deleted;
		found = isOccupiedAndValid && m_storage[index].key == key;
		if (found) {
			return { index, true };
		}
		index = (index + 1) % m_capacity;
	} while (isOccupiedAndValid);

	return { 0, false };
}

// Hash function to map a key to an index within the current capacity
size_t HashTable::Hash(int key) const {
	return key % m_capacity;
}

// Rehash the hash table by increasing the capacity and redistributing all existing buckets
void HashTable::Rehash() {
	// Increase the capacity of the hash table
	m_capacity *= 2;
	std::vector<HashItem> new_bucket(m_capacity);
	m_storage.swap(new_bucket);
	m_size = 0;

	// Redistribute existing buckets
	for (const auto& item : new_bucket) {
		if (item.occupied && !item.deleted) {
			Insert(item.key);
		}
	}
}