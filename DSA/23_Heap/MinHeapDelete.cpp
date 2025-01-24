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
    if(i == -1) return;

    int p = (i - 1) / 2;

    if(0 <= p < arr.size())
    {
        int td = arr[p];
        arr[p] = arr[i];
        arr[i] = td; if(p == 0) return;
        Heapify(arr, p);
    }

}

void MinHeapify(std::vector<int>& iArr, int iIndex)
{
    int size = iArr.size();
    int p = iIndex;
    int lc = p*2 + 1;
    int rc = p*2 + 2;

    // si - smallest index to be swap
    int si = p;
    if(lc < size && iArr[si] > iArr[lc])
        si = lc;
    if(rc < size && iArr[rc] < iArr[si])
        si = rc;

    if(si != p)
    {
        int td = iArr[p];
        iArr[p] = iArr[si];
        iArr[si] = td;
        MinHeapify(iArr, si);    
    }
}

void DeleteKey(std::vector<int>& arr, int key)
{
    if(arr.size() <= 0) return;

    int keyIndex = -1;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(arr[i] == key)
        {
            keyIndex = i;
            arr[i] = INT_MIN;
            break;
        }
    }
    
    Heapify(arr, keyIndex);

    cout << "Min-Heap after deleting root: ";
    printHeap(arr);

    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    
    cout << "Min-Heap after deleting root: ";
    printHeap(arr);

    MinHeapify(arr, 0);
}

int main() {
    vector<int> arr = {10,20,15,40,50,100,25,45};

    cout << "Original Min-Heap: ";
    printHeap(arr);

    int key = 50;
    DeleteKey(arr, 50);
    cout << "Min-Heap after deleting root: ";
    printHeap(arr);

    return 0;
}
