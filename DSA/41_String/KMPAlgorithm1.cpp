#include <iostream>
#include <vector>
#include <string>

void computeLPSArray(const std::string& pat, std::vector<int>& lps) 
{
    int pLen = pat.length();
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while (i < pLen)
    {
        if(pat[i] == pat[len])
        { 
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const std::string& txt, const std::string& pat) 
{
    int tLen = txt.length();
    int pLen = pat.length();

    std::vector<int> lps(pLen);
    computeLPSArray(pat, lps);

    lps[0] = 0;
    int i = 0;
    int j = 0;
    while (i < tLen)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }

        if(j == pLen)
        {
            std::cout << "Pattern found at " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if(j < tLen && txt[i] != pat[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main() {
    std::string text = "abcabcabcabcd";
    std::string pattern = "abcabcabcd";

    KMP(text, pattern);

    return 0;
}
