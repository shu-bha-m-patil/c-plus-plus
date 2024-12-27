#include <iostream>
#include <vector>

void MaxHeapify(std::vector<int>& iArr, int iIndex)
{
    int size = iArr.size();
    int p = iIndex;
    int lc = p*2 + 1;
    int rc = p*2 + 2;

    // li - smallest index to be swap
    int li = p;
    if(lc < size && iArr[li] < iArr[lc])
        li = lc;
    if(rc < size && iArr[rc] > iArr[li])
        li = rc;

    if(li != p)
    {
        int td = iArr[p];
        iArr[p] = iArr[li];
        iArr[li] = td;
        MaxHeapify(iArr, li);    
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

void BuildMinHeap(std::vector<int>& iArr)
{
    int lastNode = iArr.size() / 2 - 1;
    for (int i = lastNode; i >= 0; i--)
        MinHeapify(iArr, i);
}

void BuildMaxHeap(std::vector<int>& iArr)
{
    int lastNode = iArr.size() / 2 - 1;
    for (int i = lastNode; i >= 0; i--)
        MaxHeapify(iArr, i);
}

void PrintArray(std::vector<int>& iArr)
{
    for (size_t i = 0; i < iArr.size(); i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {4, 10, 3, 5, 1, 6, 9, 12, 5, 4};
    int size = arr.size();
    std::cout << "Original array: ";
    PrintArray(arr);

    BuildMinHeap(arr);
    std::cout << "Min heap: ";
    PrintArray(arr);

    BuildMaxHeap(arr);
    std::cout << "Max heap: ";
    PrintArray(arr);

    return 0;
}