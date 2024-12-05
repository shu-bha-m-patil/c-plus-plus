#include <iostream>
#include<cmath>

bool IsPalindrom(std::string str, int start, int end)
{
    if ((start == end) || std::fabs(start-end) == 1)
        return true;

    if (str[start] == str[end])
        return IsPalindrom(str, start + 1, end - 1);
    
    return false;
}

int main()
{
    std::string str("acacga");
    int start = 0;
    int end = str.size() - 1;
    if (IsPalindrom(str, start, end))
        std::cout << "The given string is palindrom string." << std::endl;
    else
        std::cout << "The given string is not a palindrom string." << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
