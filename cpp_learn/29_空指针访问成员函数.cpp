/*
 * @Description: 空指针访问成员函数
 * @Author: stone
 * @Date: 2020-02-11 12:39:02
 * @LastEditTime : 2020-02-11 13:51:34
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student()
    {
        m_Name = "";
        m_Age = 0;
    }
    Student(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }
    void showInfo1()
    {
        cout << "name is " << this->m_Name << endl;
        cout << "age is " << this->m_Age << endl;
    }
    void showInfo2()
    {
        cout << "name is " << m_Name << endl;
        cout << "age is " << m_Age << endl;
    }
    void showInfo3()
    {
        // 严谨需加一个this的判空，但是一般不这么做，减少成员函数的复杂度
        // if (this == nullptr) {
        //     cout << "this is nullptr" << endl;
        //     return;
        // }
        cout << "no info" << endl;
    }

private:
    string m_Name;
    int m_Age;
};

/**
 * @description:
 * @param :
 * @return:
 */
void Test29()
{
    Student *stu = nullptr;
    // stu->showInfo1();
    // stu->showInfo2();
    //空指针可以访问成员函数，只是该成员函数中不能有该对象传入的空指针或者隐藏的this指针
    stu->showInfo3();
    return;
}