#include <iostream>
#include <vector>
#include <utility> // For pair

using namespace std;

// Function to maintain the max-heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // Check if left child exists and is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is larger than the root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to build a max-heap from an array
void buildMaxHeap(vector<int>& arr) {
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
    //vector<int> arr = {4, 10, 3, 5, 1};
    vector<int> arr = {4, 10, 3, 5, 1, 6, 9, 12, 5, 4};


    cout << "Original array: ";
    printArray(arr);

    // Build the max-heap
    buildMaxHeap(arr);

    cout << "Max heap: ";
    printArray(arr);

    return 0;
}
