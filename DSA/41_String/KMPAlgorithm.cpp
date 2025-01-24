#include <iostream>
#include <vector>
#include <string>

void computeLPSArray(const std::string& pattern, std::vector<int>& lps) {
    int m = pattern.length();
    int length = 0;  // Length of the previous longest prefix-suffix
    lps[0] = 0;      // lps[0] is always 0

    int i = 1;       // Start from the second character
    while (i < m) 
    {
        if (pattern[i] == pattern[length]) 
        { 
            length++;
            lps[i] = length;
            i++;
        } 
        else 
        {
            if (length != 0) 
            {
                length = lps[length - 1];
            } 
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // Step 1: Create the LPS array
    std::vector<int> lps(m);
    computeLPSArray(pattern, lps);

    // Step 2: Use the LPS array to search the pattern in the text
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < n) 
    {
        if (text[i] == pattern[j]) 
        {
            i++;
            j++;
        }

        if (j == m) 
        {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        } 
        else if (i < n && text[i] != pattern[j]) 
        {
            if (j != 0) 
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
