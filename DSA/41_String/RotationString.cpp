#include <iostream>
#include <algorithm>
#include <cmath>

int Hash(std::string str, int l, int h, int wt)
{
    int j = 0, res = 0;
    for (int i = h; i >= l; i--)
    {
        int powVal = std::pow(wt,j);
        int currCharVal = str[i];
        res = res + currCharVal*powVal;
        j++;
    }

    return res;
}

void SearchPattern(std::string txt, std::string pat)
{
    std::cout << "The pattern found at ";
    int size = txt.length() - pat.length();
    for (size_t i = 0; i <= size; i++)
    {
        int j = 0;
        for (j; j < pat.length(); j++)
        {
            if(pat[j] != txt[i+j])
                break;
        }
        if(j == pat.length())
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool RabinKarpsSearch(std::string txt, std::string pat)
{
    int wt = 10;
    int patLen = pat.length();
    int texLen = txt.length();
    int pHVal = Hash(pat, 0, patLen - 1, wt);
    int wHVal = Hash(txt, 0, patLen - 1, wt);
    if(pHVal == wHVal)
        SearchPattern(txt, pat);

    int size = texLen - patLen;
    for (size_t i = 1; i <= size; i++)
    {
        // int prevCharVal = txt[i - 1];
        // int powVal = std::pow(wt, patLen - 1);
        // int currCharVal = txt[i];
        // wHVal = (wHVal - prevCharVal*powVal)*wt + currCharVal;
        wHVal = Hash(txt, i, patLen + i - 1, wt);
        if(wHVal == pHVal)
            SearchPattern(txt, pat);
    }
    return true;
}

int main()
{
    std::string txt = "abcd";
    std::string pat = "cdab";
    txt = txt + txt;
    if(RabinKarpsSearch(txt, pat))
        std::cout << "The string are ratation of each other." << std::endl;
    else
        std::cout << "The string are not ratation of each other." << std::endl;
    return 0;
}