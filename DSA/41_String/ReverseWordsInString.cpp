#include <iostream>

void ReverserString(std::string& str, int l, int h)
{
    while (l <= h)
    {
        int ts = str[l];
        str[l] = str[h];
        str[h] = ts;
        l++;
        h--;
    }
}

void ReverseWords(std::string& str)
{
    int start = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            ReverserString(str, start, i - 1);
            start = i + 1;
        }
    }
    ReverserString(str, start, str.length() - 1);
    ReverserString(str, 0, str.length() - 1);
}

int main()
{
    const int CHAR = 256;
    std::string str = "Welcome to Gfg";
    int arr[CHAR] = {0};

    std::cout << str << std::endl;
    ReverseWords(str);
    std::cout << str << std::endl;
    return 0;
}