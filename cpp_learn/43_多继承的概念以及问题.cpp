#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

class Base1 {
public:
    Base1()
    {
        m_A = 10;
    }

public:
    int m_A;
};

class Base2 {
public:
    Base2()
    {
        m_B = 20;
    }

public:
    int m_B;
};

class Son : public Base1, public Base2 {
public:
    int m_C;
    int m_D;
};

// 多继承中很容易引发二义性
void Test43()
{
    std::cout << "sizeof(Son) = " << sizeof(Son) << std::endl;
    Son s1;
    std::cout << "s1.m_A = " << s1.m_A << std::endl;
    cout << "s1.m_B = " << s1.m_B << endl;
}