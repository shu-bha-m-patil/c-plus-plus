#include <iostream>
#include <vector>

void PrintArray(std::vector<int> arr)
{
    std::cout << "The array elements are : ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int LomutoParitian(std::vector<int>& arr, int l, int h)
{
    int p = h;
    int sm = l, la = l;
    while (sm < h)
    {
        if(arr[sm] < arr[p])
        {
            std::swap(arr[sm], arr[la]);
            la++;
            PrintArray(arr);
        }
        sm++;
    }
    std::swap(arr[la], arr[p]);
    return la;
}

int KthSmallestElement(std::vector<int>& arr, int l, int h, int kthSmallElemInd)
{
    int p = LomutoParitian(arr, l, h);
    if(kthSmallElemInd < p)
        return KthSmallestElement(arr, l, p - 1, kthSmallElemInd);
    else if(kthSmallElemInd > p)
        return KthSmallestElement(arr, p + 1, h, kthSmallElemInd);
    else
        return p;
}

int main()
{
    std::vector<int> arr = {9,20,30,60,40,50,20,10,5,11};
    PrintArray (arr);
    
    int kthSmallestIndex = 3;
    int ind = KthSmallestElement(arr,0, arr.size() - 1, kthSmallestIndex);
    std::cout <<  "The " << kthSmallestIndex << " smallest element is " << arr[ind] << std::endl;
    PrintArray (arr);
    return 0;
}


