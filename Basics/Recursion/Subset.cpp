#include <iostream>
#include<cmath>

void PrintSubset(std::string str, std::string ch, int index)
{
    if (index == str.length())
    {
        std::cout << ch << ", ";
        return;
    }

    PrintSubset(str, ch, index + 1);
    PrintSubset(str, ch + str[index], index + 1);
}

int main()
{
    std::string str("abc");
    PrintSubset(str, "", 0);
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
