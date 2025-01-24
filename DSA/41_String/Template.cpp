#include <iostream>
#include <string>

int main()
{
    //char str[6] = "gfg";
    // char str[] = {'g', 'f', 'g', '\0'};
    // std::cout << str << std::endl;

    std::string str1 = "abc";
    std::string str2 = "abc";
    
    int res = str1.compare(str2);
    if(res < 0)
        std::cout << "Lesser" << std::endl;
    else if (res > 0)
        std::cout << "Greater" << std::endl;
    else
        std::cout << "Equal" << std::endl;

    std::string str = "geeksforgeeks";
    std::cout << sizeof(str) << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << str << std::endl;
    str = str + "xyz";
    std::cout << str << std::endl;
    //str = str.substr(1, 2);
    std::cout << str << std::endl;
    std::cout << str.find("eek") << std::endl;

    //std::cin >> str;
    std::getline(std::cin, str, 'K');
    std::cout << str << std::endl;

    return 0;
}