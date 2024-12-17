
#include <iostream>

int f(int n) {
    return n % 10;
}

int main()
{
    int i = f(20);
    int j = f(42);

    int arr[10] = {0};

    arr[i] = 21;
    arr[j] = 43;

    return 0;
}
