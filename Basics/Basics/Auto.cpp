#include <iostream>
#include <typeinfo>

struct student
{
    int m_rollNo;
    int m_marks;
    student(int iRNo, int iMark) : m_rollNo(iRNo), m_marks(iMark) {}
};

int main()
{
    auto a = 10;
    auto b = 15.5;
    std::cout << a << " " << typeid(a).name() << std::endl;
    std::cout << b << " " << typeid(b).name() << std::endl;

    student stud1(1, 2);
    std::cout << typeid(stud1).name() << std::endl;

    student stud2(2, 2);
    std::cout << typeid(stud2).name() << std::endl;

    return 0;
}