#include <iostream>

// Print index where pattern start
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

int main()
{
    std::string txt = "AAAAA";
    std::string pat = "AAA";
    SearchPattern(txt, pat);
    return 0;
}