#include <iostream>

bool IsPalindrom(std::string str)
{
    int l = 0, r = str.size() - 1;
    while (l <= r)
    {
        if(str[l] != str[r])
            return false;
        else { l++; r--; }
    }
    return true;
}

int main()
{
    std::string str = "aba";
    if(IsPalindrom(str))
        std::cout << "The given string is palindrom" << std::endl;
    else
        std::cout << "The given string is not palindrom" << std::endl;

    return 0;
}