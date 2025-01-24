#include <iostream>

int main()
{
    int x = 3;
    std::cout << "The left shift operator resutl is : " << (3 << 1) << std::endl;
    std::cout << "The left shift operator resutl is : " << (3 << 2) << std::endl;
    std::cout << "The left shift operator resutl is : " << (3 << 4) << std::endl;

    // 3<<1 - 000110    << operator   000110  -->  06  -->   (3 << 1)  -->  3*(2^1)
    // 3<<2 - 001100    << operator   001100  -->  12  -->   (3 << 2)  -->  3*(2^2)
    // 3<<4 - 110000    << operator   110000  -->  48  -->   (3 << 4)  -->  3*(2^4)

    x = 33;
    std::cout << "The right shift operator resutl is : " << (x >> 1) << std::endl;
    std::cout << "The right shift operator resutl is : " << (x >> 2) << std::endl;
    std::cout << "The right shift operator resutl is : " << (x >> 4) << std::endl;

    // 3<<1 - 000110    << operator   000110  -->  06  -->   (3 << 1)  -->  3*(2^1)
    // 3<<2 - 001100    << operator   001100  -->  12  -->   (3 << 2)  -->  3*(2^2)
    // 3<<4 - 110000    << operator   110000  -->  48  -->   (3 << 4)  -->  3*(2^4)

    return 0;
}
