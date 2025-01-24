#include <iostream>

int PrintTheNo(int n)
{
    if (n == 0)
        return 0;

    PrintTheNo(n - 1);
    std::cout << n << " ";
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
