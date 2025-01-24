#include <iostream>

// Print index where pattern start
void SearchPattern(std::string txt, std::string pat)
{
    std::cout << "The pattern found at ";
    int size = txt.length() - pat.length();
    int i = 0;
    while(i <= size)
    {
        int j = 0;
        for (j; j < pat.length(); j++)
        {
            if(pat[j] != txt[i+j])
                break;
        }
        if(j == pat.length())
            std::cout << i << " ";
        if(j == 0)
            i++;
        else
            i = i + j;
    }
    std::cout << std::endl;
}

int main()
{
    std::string txt = "ABCEABEFABCD";
    std::string pat = "ABCD";
    SearchPattern(txt, pat);
    return 0;
}