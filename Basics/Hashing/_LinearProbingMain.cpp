#include <iostream>

#include "HashTable.h"

int main() {
    HashTable hashTable;

    // Predefined "random" set of keys to insert
    int keysToInsert[] = { 15, 23, 42, 8, 4, 16, 23, 50, 12 };

    // Insert keys into the hash table and trigger rehashing if needed
    for (int key : keysToInsert) {
        auto insertResult = hashTable.Insert(key);
        std::cout << "Insert " << key << ": "
            << (insertResult.second ? "Inserted" : "Already exists")
            << "\n";
    }

    std::cout << std::endl;

    // Test Find function for some keys
    int testValues[] = { 23, 50, 33, 100 }; // Test with some keys present and one that isn’t
    for (int key : testValues) {
        auto findResult = hashTable.Find(key);
        std::cout << "Find " << key << ": "
            << (findResult.second ? "Found" : "Not found")
            << "\n";
    }

    std::cout << std::endl;

    // Test Remove function for selected keys
    int keysToRemove[] = { 8, 15, 100 }; // Attempt to remove keys, including one that doesn’t exist
    for (int key : keysToRemove) {
        bool removeResult = hashTable.Remove(key);
        std::cout << "Remove " << key << ": "
            << (removeResult ? "Removed" : "Not found")
            << "\n";
    }

    std::cout << std::endl;

    // Test reinserting the deleted values
    hashTable.Insert(8);
    hashTable.Insert(15);

    // Verify remaining keys after removal
    std::cout << "\nVerifying remaining keys:\n";
    for (int key : keysToInsert) {
        auto findResult = hashTable.Find(key);
        std::cout << "Find " << key << ": "
            << (findResult.second ? "Found" : "Not found")
            << "\n";
    }

    return 0;
}

/*
Why 'occupied' flag is included in HashItem structure?
- The 'occupied' flag is included in HashItem structure because we didnot want
   any particular value of a key to be dedicated to represent emptiness of an item.
- If particular value of a key is dedicated to represnet emptiness for ex. zero(0) then
  we cannot use 0 as a valid value of a key.
- Therefore 'occupied' flag is essential.
- When 'occupied' flag is set to false, it means that slot is unoccupied or empty.

Why 'deleted' flag is included in HashItem structure?
- The 'deleted' flag indicate if the respective key is deleted.
- In linear probing we donot physically delete the key,
  rather we mark the key is deleted.
- To mark the key is deleted we need 'deleted' flag.

Why deleted key is marked as deleted and not set to being empty (unoccupied)?
- Assume we inputted the following two keys viz. 50, 60 in a hash table having 10 slots.
- The hash function used is modulo 10 function.
- The setup would look as below:
  [ 50  60  EE  EE  EE  EE  EE  EE  EE  EE ]
     0   1   2   3   4   5   6   7   8   9
- EE indicate empty element and is implementd by setting 'occupied' flag of the
  respective element to false.
- Now assume we want to search for key 60. The hash value of 60 is 0.
- So the search algorithm will first check if index 0 element contains 60 if not
  it will advance to index 1 element.
- Search finds the key 60 in index 1 element so it returns that index.
- Now assume the key 50 is deleted and the respective element is set as empty element.
  [ EE  60  EE  EE  EE  EE  EE  EE  EE  EE ]
     0   1   2   3   4   5   6   7   8   9
- Now when search resumes back in search of key 60. First it will hit index 0 element.
- Since that element is set to EE. Search will think that 60 doesn't exist and will
  stop searching. However, as we notice 60 exists in the table.
- What if instead of setting element to unoccupied, it is marked as occupied and deleted.
  [ 50* 60  EE  EE  EE  EE  EE  EE  EE  EE ]
     0   1   2   3   4   5   6   7   8   9
- Now search will skip index 0 element and will proceed to index 1 element where it
  finds 60.
- Marking deleted element as empty or unoccupied breaks the linear probing path
  hence deleted element is not marked as unoccupied instead marked as occupied and deleted.
*/