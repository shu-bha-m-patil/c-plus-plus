#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapifyUp(vector<int>& arr, int i) {
    int parent = (i - 1) / 2;

    if (i > 0 && arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        heapifyUp(arr, parent); 
    }
}

void insertMaxHeap(vector<int>& arr, int value) {
    arr.push_back(value);
    
    heapifyUp(arr, arr.size() - 1);
}

void printHeap(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 3, 4, 1};

    cout << "Original Max-Heap: ";
    printHeap(arr);

    int newElement = 15;
    cout << "Inserting " << newElement << " into the Max-Heap" << endl;
    insertMaxHeap(arr, newElement);

    cout << "Max-Heap after insertion: ";
    printHeap(arr);

    return 0;
}
