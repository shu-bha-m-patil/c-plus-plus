#include <iostream>
#include <algorithm>

bool Anagram1(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
}
 
bool Anagram2(std::string str1, int l, int h, std::string str2)
{
    const int CHAR = 256;
    int arr[CHAR] = {0};
    for (size_t i = l; i < h; i++)
    {
        arr[str1[i]]++;
        arr[str2[i]]--;
    }
    for (size_t i = 0; i < str2.length(); i++)
    {
        if(arr[str1[i]] != 0)
            return false;
    }
    return true;
}

bool SearchAnagram(std::string str1, std::string str2)
{
    int size = str1.length() - str2.length();
    for (size_t i = 0; i <= size; i++)
    {
        if(Anagram2(str1, i, i + str2.length(), str2)) 
            return true;
    }
    return false;
}

int main()
{
    std::string str1 = "geeksforgeeks";
    std::string str2 = "ofrg";
    if(SearchAnagram(str1, str2))
        std::cout << "Anagram" << std::endl;
    else
        std::cout << "Not Anagram" << std::endl;

    return 0;
}