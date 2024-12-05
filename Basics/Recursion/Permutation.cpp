#include <iostream>
#include<cmath>

void PrintPermutation(std::string str, int i = 0)
{
    if (i == 2)
    {
        std::cout << str << ", ";
        return;
    }

    for (size_t j = i; j < str.size(); j++)
    {
        std::swap(str[i], str[j]);
        PrintPermutation(str, i + 1);
        std::swap(str[i], str[j]);
    }

}

int main()
{
    std::string str("abcd");

    PrintPermutation(str);
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
