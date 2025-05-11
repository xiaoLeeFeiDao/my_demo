/*
 * @Description: 静态成员变量初始化
 * @Author: stone
 * @Date: 2020-02-09 09:16:03
 * @LastEditTime : 2020-02-09 11:38:30
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    //静态成员变量：
    // 1、数据共享
    // 2、在编译阶段就分配好了内存
    // 3、在类内声明，类外初始化
    static int m_A;

    //静态成员函数：
    static void func()
    {
        // m_C = 100;  //静态成员函数不可以访问非静态成员属性
        m_A = 23; //可以访问静态成员属性，因为数据共享
        m_B = 24;
        cout << "静态成员函数调用" << endl;
    }
    void func2() //非静态成员函数可以访问非静态成员属性，也可以访问静态成员属性
    {
        m_C = 100;
        m_A = 102;
    }
    void display()
    {
        cout << "m_C = " << m_C << endl;
    }

private:
    static int m_B;
    int m_C;
    static void func3()
    {
        cout << "私有静态成员函数" << endl;
        return;
    }
};
int Person::m_A = 10;
int Person::m_B = 30;
/**
 * @description:
 * @param :
 * @return:
 */
void Test24()
{
    //访问方式
    // 1、通过对象访问
    Person p1;
    cout << "m_A = " << p1.m_A << endl;

    Person p2;
    p2.m_A = 20;
    cout << "p1.m_A = " << p1.m_A << endl;
    cout << "p2.m_A = " << p2.m_A << endl;

    // 2、通过类名来访问
    cout << "static m_A = " << Person::m_A << endl;

    //思考：为什么不通过构造函数来初始化？
    // 如果通过类名来访问这个静态变量，因为没有调用实例化对象，所以也不会调用构造函数，这时候，这个静态变量的值就是未知的，乱码
    // 静态变量在编译阶段都已经分配内存了，也就是在编译阶段这个变量的值都已经存在了

    //静态成员变量也是有访问权限的，如m_B
    // Person::m_B = 200; //m_B是一个私有的成员属性，因此类外不能访问

    //静态成员函数的调用
    p1.func();
    Person::func();

    //私有静态成员函数不可以外部访问
    // Person::func3();
    return;
}