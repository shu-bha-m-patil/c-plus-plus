#include <iostream>
#include <vector>

void PrintArray(std::vector<int> iArr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < iArr.size(); i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

void Merge(std::vector<int>& arr, int low, int mid, int high)
{
    const int ls = mid - low + 1;
    const int rs = high - mid;
    std::vector<int> lArr(ls); std::vector<int>rArr(rs);
    for (size_t i = 0; i < ls; i++) { lArr[i] = arr[low + i];} PrintArray (lArr);
    for (size_t i = 0; i < rs; i++) { rArr[i] = arr[mid + 1 + i];} PrintArray (rArr);
    
    int l = 0, r = 0, i = low;
    for (i; i < arr.size(); i++)
    {
        if(lArr[l] < rArr[r]) { if(l < ls) { arr[i] = lArr[l]; l++; } else break; }
        else  { if(r < rs) {arr[i] = rArr[r]; r++; } else break; }
    }

    while (l < ls) { arr[i] = lArr[l]; l++; i++; }
    while (r < rs) { arr[i] = rArr[r]; r++; i++; }
}

void MergeSort(std::vector<int>&arr, int low, int high)
{
    if(low >= high) return;

    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
    PrintArray (arr);
}

int main()
{
    std::vector<int>arr = {11,15,20,2,8,10,15};
    PrintArray (arr);

    MergeSort(arr, 0, 6);
    PrintArray (arr);
    
    return 0;
}


