#include <iostream>
#include <vector>
#include <algorithm>  // For std::swap

using namespace std;

// Function to restore the Max-Heap property (heapify down)
void heapifyDown(vector<int>& arr, int n, int i) {
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index
    int largest = i;        // Assume the current node is the largest

    // Check if left child exists and is greater than the current node
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the current node, swap and continue heapifying down
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to insert an element into the Max-Heap
void insertMaxHeap(vector<int>& arr, int value) {
    arr.push_back(value);  // Insert the new element at the end
    int i = arr.size() - 1;  // Index of the newly added element

    // Heapify up to restore the Max-Heap property
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            i = parent;  // Move the index to the parent
        } else {
            break;  // If the heap property is restored, stop
        }
    }
}

// Function to remove the root element (the largest element in Max-Heap)
void removeRoot(vector<int>& arr, int& n) {
    swap(arr[0], arr[n - 1]);  // Swap root with the last element
    n--;  // Decrease the size of the heap
    heapifyDown(arr, n, 0);  // Restore the Max-Heap property
}

// Function to print the heap
void printHeap(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;

    // Insert elements into the Max-Heap
    insertMaxHeap(arr, 10);
    insertMaxHeap(arr, 20);
    insertMaxHeap(arr, 15);
    insertMaxHeap(arr, 30);
    insertMaxHeap(arr, 5);

    cout << "Max-Heap after insertions: ";
    printHeap(arr);

    // Remove the root element
    int n = arr.size();
    removeRoot(arr, n);

    cout << "Max-Heap after removing root: ";
    printHeap(arr);

    return 0;
}
