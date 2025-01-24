#include <iostream>
#include <algorithm>

bool Anagram1(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
} 

bool Anagram2(std::string str1, std::string str2)
{
    const int CHAR = 256;
    int arr[CHAR] = {0};
    if(str1.length() != str2.length()) return false;
    int length = str1.length();
    for (size_t i = 0; i < length; i++)
    {
        arr[str1[i]]++;
        arr[str2[i]]--;
    }
    for (size_t i = 0; i < CHAR; i++)
        if(arr[i] != 0)
            return false;
    return true;
}

int main()
{
    std::string str1 = "abcde";
    std::string str2 = "edcba";
    if(Anagram2(str1, str2))
        std::cout << "Anagram" << std::endl;
    else
        std::cout << "Not Anagram" << std::endl;

    return 0;
}