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

    int si = i;
    int lc = i*2 + 1;
    int rc = i*2 + 2;

    if(lc < arr.size() && arr[si] > arr[lc])
        si = lc;
    if(rc < arr.size() && arr[si] > arr[rc])
        si = rc;

    if(si != i)
    {
        int td = arr[si];
        arr[si] = arr[i];
        arr[i] = td;
        Heapify(arr, si);
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
    vector<int> arr = {10,20,15,40,50,100,25,45};

    cout << "Original Min-Heap: ";
    printHeap(arr);

    DeleteRoot(arr);
    cout << "Min-Heap after deleting root: ";
    printHeap(arr);

    return 0;
}
