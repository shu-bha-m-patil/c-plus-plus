#include <iostream>
#include <vector>

template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer; // Fixed-size buffer
    size_t capacity;       // Maximum capacity of the buffer
    size_t head;           // Points to the next write position
    size_t size;           // Current number of elements in the buffer

public:
    // Constructor
    explicit CircularBuffer(size_t cap) : buffer(cap), capacity(cap), head(0), size(0) {}

    // Add an element to the circular buffer
    void push(const T& value) {
        buffer[head] = value;             // Write at the current head position
        head = (head + 1) % capacity;     // Advance the head position with wrap-around
        if (size < capacity) {
            size++; // Increment size until capacity is reached
        }
    }

    // Get an element at a specific position
    T get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        size_t actualIndex = (head + capacity - size + index) % capacity; // Map logical index to actual index
        return buffer[actualIndex];
    }

    // Get the size of the buffer (number of valid elements)
    size_t getSize() const {
        return size;
    }

    // Check if the buffer is full
    bool isFull() const {
        return size == capacity;
    }

    // Print all elements in the buffer
    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularBuffer<int> circularBuffer(5); // Create a circular buffer with a capacity of 5

    // Add elements
    circularBuffer.push(1);
    circularBuffer.push(2);
    circularBuffer.push(3);
    circularBuffer.print(); // Output: 1 2 3 4 5
    circularBuffer.push(4);
    circularBuffer.push(5);

    std::cout << "Buffer contents: ";
    circularBuffer.print(); // Output: 1 2 3 4 5

    // Add more elements, overwriting the oldest ones
    circularBuffer.push(6);
    circularBuffer.push(7);

    std::cout << "Buffer after adding more elements: ";
    circularBuffer.print(); // Output: 3 4 5 6 7

    // Access individual elements
    std::cout << "Element at index 0: " << circularBuffer.get(0) << std::endl; // Output: 3
    std::cout << "Element at index 3: " << circularBuffer.get(3) << std::endl; // Output: 6

    return 0;
}
