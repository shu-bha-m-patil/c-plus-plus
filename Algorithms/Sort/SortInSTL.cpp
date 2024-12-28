#include <iostream>
#include <algorithm>
#include <vector>

struct Point
{
    int x;
    int y;
};

bool ComparePoint(Point& p1, Point& p2)
{
    return p1.x < p2.x ? true : false;
}

int main()
{
    int arr1[] = {10,20,5,7};
    int size1 = sizeof(arr1) / sizeof(int);
    std::sort(arr1, arr1 + size1);

    // Array
    std::cout << "The array elements are : ";
    for (int e : arr1)
        std::cout << e << " ";
    std::cout << std::endl;
    std::sort(arr1, arr1 + size1, std::greater<int>());
    std::cout << "The array elements are : ";
    for (int e : arr1)
        std::cout << e << " ";
    std::cout << std::endl;

    // Vector
    std::vector<int> vect = {10,20,5,7};
    std::sort(vect.begin(), vect.end());
    std::cout << "The array elements are : ";
    for (int e : vect)
        std::cout << e << " ";
    std::cout << std::endl;
    std::sort(vect.begin(), vect.end(), std::greater<int>());
    std::cout << "The array elements are : ";
    for (int e : vect)
        std::cout << e << " ";
    std::cout << std::endl;

    // costom comparator
    Point arr[] = {{3,10},{2,8},{5,4}}; 
    int size = sizeof(arr) / sizeof(Point);
    std::sort(arr, arr + size, ComparePoint);
    std::cout << "The array elements are : ";
    for (Point e : arr)
        std::cout << e.x << "," << e.y << " ";
    std::cout << std::endl;
   
    return 0;
}


