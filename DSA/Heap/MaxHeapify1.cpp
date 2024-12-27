#include <iostream>
#include <vector>

void Heapify(std::vector<int>& iArr, int iIndex)
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
        Heapify(iArr, li);    
    }
}

void BuildHeap(std::vector<int>& iArr)
{
    int lastNode = iArr.size() / 2 - 1;
    for (int i = lastNode; i >= 0; i--)
        Heapify(iArr, i);
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

    BuildHeap(arr);
    
    std::cout << "Min heap: ";
    PrintArray(arr);

    return 0;
}