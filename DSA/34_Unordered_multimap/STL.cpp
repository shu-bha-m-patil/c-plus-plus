#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename Key, typename Value>
class UnorderedMultimap {
private:
    // A bucket stores a list of key-value pairs
    std::vector<std::list<std::pair<Key, Value>>> table;
    size_t bucket_count;
    size_t num_elements;

    // Hash function to map elements to a bucket
    size_t hash(const Key& key) const {
        return std::hash<Key>{}(key) % bucket_count;
    }

public:
    // Constructor: Initializes with a default bucket count
    UnorderedMultimap(size_t initial_bucket_count = 10) 
        : bucket_count(initial_bucket_count), num_elements(0) {
        table.resize(bucket_count);
    }

    // Insert a key-value pair into the multimap
    void insert(const Key& key, const Value& value) {
        size_t index = hash(key);
        table[index].push_back({key, value});  // Insert into the corresponding bucket
        ++num_elements;
    }

    // Find an element by key (finds the first occurrence)
    bool find(const Key& key) const {
        size_t index = hash(key);
        const auto& bucket = table[index];

        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return true;  // Element found
            }
        }
        return false;  // Element not found
    }

    // Count occurrences of a key
    size_t count(const Key& key) const {
        size_t index = hash(key);
        const auto& bucket = table[index];

        size_t count = 0;
        for (const auto& pair : bucket) {
            if (pair.first == key) {
                ++count;
            }
        }
        return count;
    }

    // Erase all occurrences of a key
    void erase(const Key& key) {
        size_t index = hash(key);
        auto& bucket = table[index];

        auto it = bucket.begin();
        while (it != bucket.end()) {
            if (it->first == key) {
                it = bucket.erase(it);  // Remove the key-value pair
                --num_elements;
            } else {
                ++it;
            }
        }
    }

    // Rehash: Resize the table and redistribute elements
    void rehash(size_t new_bucket_count) {
        std::vector<std::list<std::pair<Key, Value>>> new_table(new_bucket_count);

        // Re-insert elements into the new table
        for (auto& bucket : table) {
            for (const auto& pair : bucket) {
                size_t index = std::hash<Key>{}(pair.first) % new_bucket_count;
                new_table[index].push_back(pair);
            }
        }

        table = std::move(new_table);
        bucket_count = new_bucket_count;
    }

    // Print the contents of the unordered multimap (for debugging)
    void print() const {
        for (size_t i = 0; i < bucket_count; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    // Get the size of the unordered multimap
    size_t size() const {
        return num_elements;
    }
};

int main() {
    UnorderedMultimap<int, std::string> myMap;

    // Insert some key-value pairs
    myMap.insert(10, "Ten");
    myMap.insert(10, "Ten");
    myMap.insert(20, "Twenty");
    myMap.insert(10, "Another Ten");
    myMap.insert(30, "Thirty");

    // Print the contents
    std::cout << "Contents of the unordered multimap:" << std::endl;
    myMap.print();

    // Find an element
    std::cout << "Find 10: " << (myMap.find(10) ? "Found" : "Not Found") << std::endl;

    // Count occurrences
    std::cout << "Count of 10: " << myMap.count(10) << std::endl;

    // Erase all occurrences of 10
    myMap.erase(10);
    std::cout << "Contents after erasing all 10s:" << std::endl;
    myMap.print();

    return 0;
}
