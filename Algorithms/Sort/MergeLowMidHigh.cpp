#include <iostream>
#include <vector>

void PrintArray(std::vector<int> iArr, int iSize)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < iSize; i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

void Merge(std::vector<int>& arr, int low, int mid, int high)
{
    const int ls = mid - low + 1;
    const int rs = high - mid;
    std::vector<int> lArr(ls); std::vector<int>rArr(rs);
    for (size_t i = 0; i < ls; i++) { lArr[i] = arr[low + i];} PrintArray (lArr, ls);
    for (size_t i = 0; i < rs; i++) { rArr[i] = arr[mid + 1 + i];} PrintArray (rArr, rs);
    
    int l = 0, r = 0, i = low;
    for (i; i < arr.size(); i++)
    {
        if(lArr[l] < rArr[r]) { if(l < ls) { arr[i] = lArr[l]; l++; } else break; }
        else  { if(r < rs) {arr[i] = rArr[r]; r++; } else break; }
    }

    while (l < ls) { arr[i] = lArr[l]; l++; i++; }
    while (r < rs) { arr[i] = rArr[r]; r++; i++; }
}

int main()
{
    std::vector<int>arr = {10,15,20,40,8,11,15};
    int size = sizeof(arr) / sizeof(int);
    int low = 0;
    int mid = 3;
    int high = 6;
    PrintArray (arr, size);

    Merge(arr, low, mid, high);
    PrintArray (arr, size);
    
    return 0;
}


