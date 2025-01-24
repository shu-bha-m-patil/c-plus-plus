#include <iostream>
#include <vector>
#include <list>
#include <functional>  // for std::hash

template <typename T>
class UnorderedMultiset {
private:
    std::vector<std::list<T>> table;  // Hash table (vector of lists)
    size_t num_elements;              // Number of elements in the multiset
    size_t bucket_count;              // Number of buckets

    // Hash function to map elements to bucket
    size_t hash(const T& key) const {
        return std::hash<T>{}(key) % bucket_count;  // Simple hash function
    }

public:
    // Constructor: Set initial bucket count (default to 10)
    UnorderedMultiset(size_t buckets = 10) : bucket_count(buckets), num_elements(0) {
        table.resize(bucket_count);  // Resize table to fit initial bucket count
    }

    // Insert an element into the multiset
    void insert(const T& key) {
        size_t index = hash(key);  // Get the bucket index
        table[index].push_back(key);  // Insert the element into the bucket
        ++num_elements;  // Increase the number of elements
    }

    // Find an element in the multiset
    bool contains(const T& key) const {
        size_t index = hash(key);  // Get the bucket index
        const auto& bucket = table[index];
        for (const auto& elem : bucket) {
            if (elem == key) {
                return true;  // Found the element
            }
        }
        return false;  // Element not found
    }

    // Erase one occurrence of an element
    bool erase(const T& key) {
        size_t index = hash(key);  // Get the bucket index
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);  // Erase the element
                --num_elements;  // Decrease the number of elements
                return true;
            }
        }
        return false;  // Element not found
    }

    // Get the number of occurrences of a particular element
    size_t count(const T& key) const {
        size_t index = hash(key);  // Get the bucket index
        const auto& bucket = table[index];
        size_t count = 0;
        for (const auto& elem : bucket) {
            if (elem == key) {
                ++count;  // Count the occurrences of the element
            }
        }
        return count;
    }

    // Rehash: Resize the table and redistribute elements to new buckets
    void rehash(size_t new_bucket_count) {
        std::vector<std::list<T>> new_table(new_bucket_count);
        for (const auto& bucket : table) {
            for (const auto& elem : bucket) {
                size_t new_index = std::hash<T>{}(elem) % new_bucket_count;
                new_table[new_index].push_back(elem);  // Insert the element in the new bucket
            }
        }
        table = std::move(new_table);  // Move to the new table
        bucket_count = new_bucket_count;  // Update the bucket count
    }

    // Print the contents of the unordered multiset (for debugging)
    void print() const {
        for (size_t i = 0; i < bucket_count; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& elem : table[i]) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    // Get the size of the multiset (number of elements)
    size_t size() const {
        return num_elements;
    }
};

int main() {
    UnorderedMultiset<int> ums;

    ums.insert(10);
    ums.insert(20);
    ums.insert(10);
    ums.insert(30);
    ums.insert(10);

    std::cout << "Contents of the unordered multiset:" << std::endl;
    ums.print();

    std::cout << "Count of 10: " << ums.count(10) << std::endl;
    std::cout << "Contains 20? " << (ums.contains(20) ? "Yes" : "No") << std::endl;

    ums.erase(10);
    std::cout << "Contents after erasing one occurrence of 10:" << std::endl;
    ums.print();

    return 0;
}
