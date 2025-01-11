#include <iostream>

// When convert from int to unsigne_int 
// +ve value remains as it is 
// -ve --> -1 ---> 11111111 11111111 11111111 11111111
// for unsigne it becomes max value of int

struct student
{
    int _rNo;
    student(int iRNo) : _rNo(iRNo) {}
};

struct mechStud : public student
{
    int _mark;
    mechStud(mechStud& iStud) : student(iStud._rNo), _mark(iStud._mark) {}
    mechStud(int iRNo, int iMark) : student(iRNo), _mark(iMark) {}
};

struct civilStud : public student
{
    std::string _name;
    civilStud(civilStud& iStud) : student(iStud._rNo), _name(iStud._name) {}
    civilStud(int iRNo, std::string iName) : student(iRNo), _name(iName) {}
};


int main()
{
    int x = -1;
    std::cout << x << std::endl;

    unsigned int y = x;
    std::cout << y << std::endl;

    int a = 15;
    int b = 2;
    //double c = 15/2; // --> 7
    double c = double(15)/2; // --> 7.5
    std::cout << c << std::endl;

    student* stud1 = new mechStud(1, 98);

    mechStud* stud11 = static_cast<mechStud*>(stud1);
    std::cout << stud11->_mark << std::endl;

    civilStud* stud2 = static_cast<civilStud*>(stud1);
    std::cout << stud2->_name << std::endl;

    return 0;
}
