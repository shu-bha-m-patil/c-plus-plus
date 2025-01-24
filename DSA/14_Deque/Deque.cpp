#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class BlockBasedDeque {
private:
    static const size_t BLOCK_SIZE = 4; // Size of each block
    std::vector<T*> _blockTable;         // Array of pointers to blocks
    size_t _frontIndex;                  // Logical front index
    size_t _backIndex;                   // Logical back index
    size_t _totalSize;                   // Total number of elements

    // Allocate a new block of fixed size
    T* allocateBlock() {
        return new T[BLOCK_SIZE]();
    }

    // Get block index and offset for a given logical index
    std::pair<size_t, size_t> getBlockAndOffset(size_t logicalIndex) const {
        size_t blockIndex = logicalIndex / BLOCK_SIZE;
        size_t offset = logicalIndex % BLOCK_SIZE;
        return { blockIndex, offset };
    }

    // Ensure a block exists in the table
    void ensureBlock(size_t blockIndex) {
        if (blockIndex >= _blockTable.size()) {
            _blockTable.resize(blockIndex + 1, nullptr);
        }
        if (_blockTable[blockIndex] == nullptr) {
            _blockTable[blockIndex] = allocateBlock();
        }
    }

public:
    BlockBasedDeque() : _frontIndex(BLOCK_SIZE), _backIndex(BLOCK_SIZE), _totalSize(0) {
        _blockTable.resize(1);
        _blockTable[0] = allocateBlock();
    }

    ~BlockBasedDeque() {
        for (T* block : _blockTable) {
            delete[] block;
        }
    }

    // Push an element at the back
    void pushBack(const T& value) {
        ensureBlock(_backIndex / BLOCK_SIZE);
        auto [blockIndex, offset] = getBlockAndOffset(_backIndex);
        _blockTable[blockIndex][offset] = value;
        _backIndex++;
        _totalSize++;
    }

    // Push an element at the front
    void pushFront(const T& value) {
        if (_frontIndex == 0) {
            _blockTable.insert(_blockTable.begin(), allocateBlock());
            _frontIndex += BLOCK_SIZE;
            _backIndex += BLOCK_SIZE;
        }
        _frontIndex--;
        auto [blockIndex, offset] = getBlockAndOffset(_frontIndex);
        _blockTable[blockIndex][offset] = value;
        _totalSize++;
    }

    // Pop an element from the back
    void popBack() {
        if (_totalSize == 0) throw std::out_of_range("Deque is empty");
        _backIndex--;
        _totalSize--;
    }

    // Pop an element from the front
    void popFront() {
        if (_totalSize == 0) throw std::out_of_range("Deque is empty");
        _frontIndex++;
        _totalSize--;
    }

    // Access elements using logical indices
    T& operator[](size_t index) const {
        if (index >= _totalSize) throw std::out_of_range("Index out of range");
        size_t logicalIndex = _frontIndex + index;
        auto [blockIndex, offset] = getBlockAndOffset(logicalIndex);
        return _blockTable[blockIndex][offset];
    }

    // Get the size of the deque
    size_t size() const {
        return _totalSize;
    }
};

int main() {
    BlockBasedDeque<int> deque;

    // Adding elements to the back
    deque.pushBack(4);
    deque.pushBack(5);
    deque.pushBack(6);
    deque.pushBack(7);
    deque.pushBack(8);

    // Adding elements to the front
    deque.pushFront(3);
    deque.pushFront(2);
    deque.pushFront(1);
    deque.pushFront(0);
    deque.pushFront(-1);
    deque.pushFront(-2);

    // Access elements
    std::cout << "Deque elements: ";
    for (size_t i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;

    // Pop elements
    deque.popFront();
    deque.popBack();

    std::cout << "After popping: ";
    for (size_t i = 0; i < deque.size(); ++i) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
