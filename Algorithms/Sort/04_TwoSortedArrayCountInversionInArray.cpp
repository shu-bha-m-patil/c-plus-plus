#include <iostream>
#include <vector>

void PrintArray(std::vector<int> iArr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < iArr.size(); i++)
        std::cout << iArr[i] << " ";
    std::cout << std::endl;
}

void Merge(std::vector<int>& arr, int low, int mid, int high, int& inversions)
{
    const int ls = mid - low + 1;
    const int rs = high - mid;
    std::vector<int> lArr(ls); std::vector<int>rArr(rs);
    for (size_t i = 0; i < ls; i++) { lArr[i] = arr[low + i];}
    for (size_t i = 0; i < rs; i++) { rArr[i] = arr[mid + 1 + i];}
    
    int l = 0, r = 0, i = low;
    for (i; i < arr.size(); i++)
    {
        if(lArr[l] < rArr[r]) { if(l < ls) { arr[i] = lArr[l]; l++; } else break; }
        else  { if(r < rs) {arr[i] = rArr[r]; r++; inversions = inversions + (ls - l);} else break; }
    }

    while (l < ls) { arr[i] = lArr[l]; l++; i++; }
    while (r < rs) { arr[i] = rArr[r]; r++; i++; }
}

void MergeSort(std::vector<int>&arr, int low, int high, int& inversions)
{
    if(low >= high) return;

    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid, inversions);
    MergeSort(arr, mid + 1, high, inversions);
    Merge(arr, low, mid, high, inversions);
}

int CountInversionInArray(std::vector<int>&arr, int& inversions)
{
    int count = 0;
    MergeSort(arr, 0, arr.size() - 1, inversions);
    return count;
}

int main()
{
    std::vector<int>arr = {2,11,8,5,3,6,9,13};
    PrintArray (arr);
    int inversions = 0;
    CountInversionInArray(arr, inversions);
    std::cout << "The no of inversions are " << inversions << std::endl;

    PrintArray (arr);
    return 0;
}


