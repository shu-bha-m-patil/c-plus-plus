#include <iostream>
#include <vector>

using namespace std;

void printHeap(const vector<int>& arr) 
{
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void Heapify(std::vector<int>&arr, int i)
{
    if(arr.size() <= 0) return;

    int li = i;
    int lc = i*2 + 1;
    int rc = i*2 + 2;

    if(lc < arr.size() && arr[li] < arr[lc])
        li = lc;
    if(rc < arr.size() && arr[li] < arr[rc])
        li = rc;

    if(li != i)
    {
        int td = arr[li];
        arr[li] = arr[i];
        arr[i] = td;
        Heapify(arr, li);
    }
}

void DeleteRoot(std::vector<int>& arr)
{
    if(arr.size() <= 0) return;

    arr[0] = arr.back();
    arr.pop_back();

    Heapify(arr, 0);
}

int main() {
    vector<int> arr = {30, 10, 15, 20, 5};

    cout << "Original Max-Heap: ";
    printHeap(arr);

    DeleteRoot(arr);
    cout << "Max-Heap after deleting root: ";
    printHeap(arr);

    return 0;
}
