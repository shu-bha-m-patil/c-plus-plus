#include <iostream>

int main()
{
    std::string str = "geeksforgeeks";
    int arr[26];
    for (size_t i = 0; i <= 26; i++)
        arr[i] = 0;

    for (size_t i = 0; i < str.size(); i++)
        arr[str[i] - 'a']++;
    
    for (size_t i = 0; i <= 26; i++)
    { 
        if(arr[i] > 0)
        {
            std::cout << (char)(i + 'a') << "-" << arr[i] << " ";
        }
    }

    return 0;
}