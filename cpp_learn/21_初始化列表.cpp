/*
 * @Description: 初始化列表
 * @Author: stone
 * @Date: 2020-02-06 21:20:20
 * @LastEditTime : 2020-02-07 14:07:54
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person() :
        m_A(4), m_B(5), m_C(6)
    {
    }
    Person(int a, int b, int c) :
        m_A(a), m_B(b), m_C(c) //也可以只初始化指定成员属性，可随意自定义
    {
    }
    // Person(int a, int b, int c)
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }
    void display()
    {
        cout << "m_A = " << m_A << endl;
        cout << "m_B = " << m_B << endl;
        cout << "m_C = " << m_C << endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test21()
{
    //实例化方法1，对应的是有参构造Person(int a, int b, int c)
    // Person p0(1, 2, 3);
    // p0.display();

    //实例化方法2，初始化列表，对应的有参构造方式为：Person(int a, int b, int c):m_A(a),m_B(b),m_C(c)
    Person p1;
    Person p2(1, 2, 3);
    p1.display();
    return;
}