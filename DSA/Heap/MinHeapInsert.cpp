#include <iostream>
#include <vector>

using namespace std;

// void heapifyUp(vector<int>& arr, int i) {
//     int parent = (i - 1) / 2;

//     if (i > 0 && arr[i] < arr[parent]) {
//         swap(arr[i], arr[parent]);
//         heapifyUp(arr, parent); 
//     }
// }

void heapifyUp(vector<int>& arr, int i) {
    int p = (i - 1) / 2;

    if(p >= 0 && arr[p] > arr[i])
    {
        int td = arr[p];
        arr[p] = arr[i];
        arr[i] = td;
        heapifyUp(arr, p);
    }
}

// void insertMinHeap(vector<int>& arr, int value) {
//     arr.push_back(value);
    
//     heapifyUp(arr, arr.size() - 1);
// }

void insertMinHeap(vector<int>& arr, int value) {
    arr.push_back(value);

    heapifyUp(arr, arr.size() -1);
}

void printHeap(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10,20,15,40,50,100,25,45};

    cout << "Original Min-Heap: ";
    printHeap(arr);

    int newElement = 2;
    cout << "Inserting " << newElement << " into the Min-Heap" << endl;
    insertMinHeap(arr, newElement);

    cout << "Min-Heap after insertion: ";
    printHeap(arr);

    return 0;
}
