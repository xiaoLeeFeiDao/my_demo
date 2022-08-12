/*
 * @Description: 函数调用运算符重载
 * @Author: stone
 * @Date: 2020-02-17 09:41:20
 * @LastEditTime : 2020-02-18 15:02:31
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person()
    {
        this->m_Age = 0;
    }
    Person(int Age)
    {
        this->m_Age = Age;
    }
    Person(const Person &user)
    {
        this->m_Age = user.m_Age;
    }

    void showInfo()
    {
        cout << "m_Age = " << this->m_Age << endl;
        return;
    }
    void operator()(string text)
    {
        cout << text << endl;
    }
    int operator()(int a, int b)
    {
        return a + b;
    }
    ~Person()
    {
        ;
    }

private:
    int m_Age;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test37()
{
    Person *p = new Person(18);
    (*p)("hello");
    cout << (*p)(2, 3) << endl;
    return;
}