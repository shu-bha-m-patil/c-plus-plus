
#include <iostream>

int f(int n);

int main()
{
    int i = f(20);
    int j = f(42);
}

int f(int n) {
    return n % 10;
}

/*
The value returned from function 'f' can be called as a hash value of the given input value.
The function 'f' is called hash function.
*/