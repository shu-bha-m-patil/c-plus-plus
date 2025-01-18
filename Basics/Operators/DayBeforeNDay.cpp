#include <iostream>

void PrintDays(int day)
{
    std::string str;
    switch (day)
    {
        case 0:
        {
            str = "Sunday";
            break;
        }
        case 1:
        {
            str = "Monday";
            break;
        }
        case 2:
        {
            str = "Tuesday";
            break;
        }
        case 3:
        {
            str = "Wednesday";
            break;
        }
        case 4:
        {
            str = "Thursday";
            break;
        }
        case 5:
        {
            str = "Friday";
            break;
        }
        case 6:
        {
            str = "Saturday";
            break;
        }
        default:
        {
            break;
        }
    }
     std::cout << str << std::endl;
}

int main()
{
    int d = 5;
    int n = 9;

    int res = n % 7;
    res = d - res;

    if (res > 0)
        PrintDays(res);
    else
        PrintDays(res + 7);
    return 0;
}