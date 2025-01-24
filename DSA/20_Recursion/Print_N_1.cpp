#include <iostream>

int PrintTheNo(int n)
{
    if (n == 0)
        return 0;
    std::cout << n << " ";
    return PrintTheNo(n - 1);
}

int main()
{
    int n = 0;
    std::cout << "Enter the no ";
    std::cin >> n;
    PrintTheNo(n);
    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}
