#include <iostream>
#include <vector>
#include <list>
#include <functional> // For std::hash

template <typename T>
class UnorderedSet {
private:
    // Hash table: each bucket is a list
    std::vector<std::list<T>> table;
    size_t num_elements; // Number of elements in the set
    size_t bucket_count; // Number of buckets

    // Hash function
    size_t hash(const T& key) const {
        return std::hash<T>{}(key) % bucket_count;
    }

public:
    // Constructor
    UnorderedSet(size_t buckets = 10) : bucket_count(buckets), num_elements(0) {
        table.resize(bucket_count);
    }

    // Insert an element
    bool insert(const T& key) {
        size_t index = hash(key);
        // Check if the key already exists in the bucket
        for (const auto& element : table[index]) {
            if (element == key) {
                return false; // Key already exists
            }
        }
        // Insert the key into the bucket
        table[index].push_back(key);
        ++num_elements;
        return true;
    }

    // Check if an element exists
    bool contains(const T& key) const {
        size_t index = hash(key);
        for (const auto& element : table[index]) {
            if (element == key) {
                return true; // Key found
            }
        }
        return false; // Key not found
    }

    // Remove an element
    bool erase(const T& key) {
        size_t index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                --num_elements;
                return true; // Key removed
            }
        }
        return false; // Key not found
    }

    // Get the load factor (num_elements / bucket_count)
    double load_factor() const {
        return static_cast<double>(num_elements) / bucket_count;
    }

    // Rehash: Resize the table and reassign elements to new buckets
    void rehash(size_t new_bucket_count) {
        std::vector<std::list<T>> new_table(new_bucket_count);
        for (const auto& bucket : table) {
            for (const auto& element : bucket) {
                size_t new_index = std::hash<T>{}(element) % new_bucket_count;
                new_table[new_index].push_back(element);
            }
        }
        table = std::move(new_table);
        bucket_count = new_bucket_count;
    }

    // Print the hash table (for debugging)
    void print() const {
        for (size_t i = 0; i < bucket_count; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& element : table[i]) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnorderedSet<int> uset;

    uset.insert(10);
    uset.insert(20);
    uset.insert(15);
    uset.insert(10); // Duplicate, won't be inserted

    std::cout << "Hash table after inserts:" << std::endl;
    uset.print();

    std::cout << "\nContains 15? " << (uset.contains(15) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 30? " << (uset.contains(30) ? "Yes" : "No") << std::endl;

    uset.erase(15);
    std::cout << "\nHash table after erasing 15:" << std::endl;
    uset.print();

    return 0;
}
