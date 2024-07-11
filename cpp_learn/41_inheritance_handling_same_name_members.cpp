
#include <iostream>
#include <string>
using namespace std;
#include "cpp_learn_inner.h"
class Base {
public:
    Base()
    {
        this->m_A = 100;
    }
    void func()
    {
        cout << "父类func调用" << endl;
        return;
    }
    // 如果子类中有同名函数，则所有父类中所有同名的函数都会被隐藏
    void func(int a)
    {
        this->m_A = a;
        return;
    }
    int m_A;

protected:
private:
};
class Son : public Base {
public:
    int m_A;
    Son()
    {
        this->m_A = 200;
    }
    void func()
    {
        cout << "子类的func调用" << endl;
        return;
    }

protected:
private:
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test41()
{
    Son s;
    cout << s.m_A << endl;
    // 如果需要访问父类中的同名成员属性，需要加作用域，遵循就近原则，如果子类中有，就用子类的
    cout << "Base中的m_A = " << s.Base ::m_A << endl;
    // 如果需要访问父类中的同名成员函数，需要加作用域，遵循就近原则，如果子类中有，就用子类的
    // 如果子类中出现一次同名的函数，则系统会将父类中的所有同名函数隐藏(包括重载函数)
    s.func();
    s.Base::func();
    // 只是系统将父类的所有同名函数隐藏，而不是覆盖或者删除，因此可以通过加作用域的方式调用
    // s.func(300); // 该处编译报错，由于有同名函数时，系统隐藏了父类中的有参构造函数
    // 如果想要调用父类中的有参构造，则需要加作用域
    s.Base::func(400);
    return;
}