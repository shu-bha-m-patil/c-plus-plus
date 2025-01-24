#include <iostream>
#include <vector>

using namespace std;

// Function to maintain the min-heap property
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is smaller than the root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // Check if right child exists and is smaller than the root
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not the root, swap and recursively heapify the affected subtree
    if (smallest != i) {
        swap(arr[i], arr[smallest]); // Swap

        // Recursively heapify the affected subtree
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap from an array
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();

    // Start heapifying from the last non-leaf node, which is at index n//2 - 1
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example array
    vector<int> arr = {4, 10, 3, 5, 1, 6, 9, 12, 5, 4};

    cout << "Original array: ";
    printArray(arr);

    // Build the min-heap
    buildMinHeap(arr);

    cout << "Min heap: ";
    printArray(arr);

    return 0;
}
