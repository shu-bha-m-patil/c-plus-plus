#include <iostream>
#include <vector>

void MaxHeapify(std::vector<int>& iArr, int iSize, int iIndex)
{
    int p = iIndex;
    int lc = p*2 + 1;
    int rc = p*2 + 2;

    // li - largest index to be swap
    int li = p;
    if(lc < iSize && iArr[li] < iArr[lc])
        li = lc;
    if(rc < iSize && iArr[rc] > iArr[li])
        li = rc;

    if(li != p)
    {
        int td = iArr[p];
        iArr[p] = iArr[li];
        iArr[li] = td;
        MaxHeapify(iArr, iSize, li);    
    }
}

void BuildMaxHeap(std::vector<int>& iArr)
{
    int lastNode = iArr.size() / 2 - 1;
    for (int i = lastNode; i >= 0; i--)
        MaxHeapify(iArr, iArr.size() - 1, i);
}

void PrintArray(std::vector<int>& iArr)
{
    for (size_t i = 0; i < iArr.size(); i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

void SortHeap(std::vector<int>& iArr)
{
    for (int i = iArr.size() - 1; i >= 0; --i)
    {
        int td = iArr[0];
        iArr[0] = iArr[i];
        iArr[i] = td;
        MaxHeapify(iArr, i, 0);

        std::cout << "Max heap: ";
        PrintArray(iArr);
    }
}

int main()
{
    std::vector<int> arr = {4, 10, 3, 5, 1, 6, 9, 12, 5, 4};
    int size = arr.size();
    std::cout << "Original array: ";
    PrintArray(arr);

    BuildMaxHeap(arr);

    SortHeap(arr);
    std::cout << "Sorted Max heap: ";
    PrintArray(arr);

    return 0;
}