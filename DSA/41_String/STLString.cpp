#include <iostream>
#include <cstring> // For strlen, strcpy

class String {
private:
    char* data;
    size_t size;
    size_t capacity;

public:
    // Default constructor
    String() : data(nullptr), size(0), capacity(0) {}

    // Constructor from C-style string
    String(const char* str) {
        size = strlen(str);
        capacity = size + 1; // +1 for null terminator
        data = new char[capacity];
        strcpy(data, str);
    }

    // Copy constructor
    String(const String& other) {
        size = other.size;
        capacity = other.capacity;
        data = new char[capacity];
        strcpy(data, other.data);
    }

    // Move constructor
    String(String&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Operator overloading for assignment
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            data = new char[capacity];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Accessor
    char operator[](size_t index) const {
        return data[index];
    }

    // Append operation
    void append(const char* str) {
        size_t new_size = size + strlen(str);
        if (new_size >= capacity) {
            capacity = new_size + 1; // +1 for null terminator
            char* new_data = new char[capacity];
            strcpy(new_data, data);
            strcat(new_data, str);

            delete[] data;
            data = new_data;
        } else {
            strcat(data, str);
        }
        size = new_size;
    }

    // Print function
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    String s("Hello");
    s.append(", World!");
    s.print(); // Output: Hello, World!
    return 0;
}
