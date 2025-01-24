#include <iostream>

int main()
{
    const int CHAR = 256;
    std::string str = "abccb";
    int arr[CHAR] = {0};

    for (size_t i = 0; i < str.size(); i++)
        arr[str[i]]++;
    
    for (int i = str.length() - 1; i >= 0; i--)
        if(arr[str[i]] == 1)
        {
            std::cout << "The right most non repeatating character is " << str[i] << std::endl;
            break;
        }

    return 0;
}