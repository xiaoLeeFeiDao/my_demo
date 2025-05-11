/*
 * @Description: this指针
 * @Author: stone
 * @Date: 2020-02-10 17:26:20
 * @LastEditTime : 2020-02-12 11:09:18
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    Teacher()
    {
        m_A = 0;
    }
    Teacher(int a)
    {
        m_A = a;
    }
    void func() //为什么非静态成员函数可以访问非静态成员属性，而静态成员函数不可以访问非静态成员属性？由于非静态成员函数隐藏了一个this指针
    // void func(this)
    {
        m_A = 110;
        cout << "m_A " << m_A << endl;
        return;
    }
    static void func2()
    {
        // m_A = 20;    //不可以访问非静态成员属性
        return;
    }
    void setMemberValue(int m_A)
    {
        // m_A = m_A;
        this->m_A = m_A;
    }
    int getMemberValue()
    {
        return m_A;
    }
    Teacher &setObjValue(const Teacher &p) //  利用this指针进行累加
    {
        this->m_A += p.m_A;
        return *this;
    }
    Teacher setCopyObjValue(const Teacher &p) //  利用this指针进行累加
    {
        this->m_A += p.m_A;
        return *this;
    }
    void display()
    {
        cout << "m_A = " << m_A << endl;
    }

private:
    int m_A;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test28()
{
    // this指针指向被调用的成员函数所属的对象
    Teacher p1;
    // p1.func();

    // this指针的用法:
    //  1、可以解决命名冲突
    //如果setMemberValue中m_A = m_A
    //  p1.setMemberValue(19); //如果这样调用传入到setMemberValue中，系统会认为m_A为同一个变量
    //  cout << p1.getMemberValue() << endl; //这里查看这个m_A的值，并未修改为19
    //如果setMemberValue中使用this指针即 this->m_A = m_A则可以解决上面的问题

    Teacher p2(28);
    p1.setObjValue(p2).setObjValue(p2); //链式编程
    p1.display();

    p1.setCopyObjValue(p2).setCopyObjValue(p2).setCopyObjValue(p2); //链式编程
    p1.display();
    return;
}