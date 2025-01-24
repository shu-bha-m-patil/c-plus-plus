#include <iostream>

bool SubSequence(std::string str1, std::string str2)
{
    int i1 = 0, i2 = 0;
    int s1 = str1.size(), s2 = str2.size();
    while (i1 < s1 && i2 < s2)
    {
        if(str1[i1] == str2[i2]) {i1++; i2++;}
        else{i1++;}
    } 
    
    return i2 == s2; 
}

int main()
{
    std::string str1 = "abcde";
    std::string str2 = "bcda";
    if(SubSequence(str1, str2))
        std::cout << "String2 is subsequence of string1" << std::endl;
    else
        std::cout << "String2 is not subsequence of string1" << std::endl;

    return 0;
}