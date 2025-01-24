#include <iostream>

int main()
{
    int x = 33;
    std::cout << "The right shift operator resutl is : " << (x >> 1) << std::endl;
    std::cout << "The right shift operator resutl is : " << (x >> 2) << std::endl;

    return 0;
}

/*
        33 - 100001
     33>>1 -  010000    >> operator   010000  -->  16
     16>>2 -  001000    >> operator   001000  -->  8

*/