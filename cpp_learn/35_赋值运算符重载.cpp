/*
 * @Description: 赋值运算符重载
 * @Author: stone
 * @Date: 2020-02-14 22:12:28
 * @LastEditTime : 2020-02-15 19:37:58
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <cstring>
#include <iostream>
using namespace std;

class Person {
public:
    Person()
    {
        this->m_Name = nullptr;
        this->m_Age = 0;
    }
    Person(const char *name, int age)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
        this->m_Age = age;
    }
    Person(const Person &user)
    {
        //系统提供的值拷贝
        // this->m_Name = user.m_Name;

        //自定义属性深拷贝
        this->m_Name = new char[strlen(user.m_Name + 1)];
        strcpy(this->m_Name, user.m_Name);
        this->m_Age = user.m_Age;
    }
    //系统提供的默认operator=构造函数
    // void operator=(const Person& p){
    //     this->m_Name = p.m_Name;
    //     this->m_Age = p.m_Age;
    // }

    // 自定义operator=构造函数，即=运算符的重载
    Person &operator=(const Person &user)
    {
        //需要对=的左值的指针判空
        if (this->m_Name != nullptr) {
            delete[] this->m_Name;
            this->m_Name = nullptr;
        }
        this->m_Name = new char[strlen(user.m_Name + 1)];
        strcpy(this->m_Name, user.m_Name);
        this->m_Age = user.m_Age;
        return *this;
    }
    void showInfo()
    {
        cout << "m_Name = " << this->m_Name << endl;
        cout << "m_Age = " << this->m_Age << endl;
        return;
    }
    ~Person()
    {
        if (this->m_Name != nullptr) {
            cout << "析构" << endl;
            delete[] this->m_Name;
            this->m_Name = nullptr;
        };
    }

private:
    char *m_Name;
    int m_Age;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test35()
{
    Person p1("tom", 19);
    Person p2("stone", 20);
    // p1.showInfo();
    // p2.showInfo();

    // p1 = p2; //隐式的拷贝构造(浅拷贝)，系统提供的operator=构造函数，为简单的值拷贝，如果类内成员属性有指针，会造成析构时doublefree
    // p1.showInfo();
    // p2.showInfo();

    //因此需要自定义实现，来修改系统的operator=值拷贝构造函数，即自定义重载operator=，来实现深拷贝
    p1 = p2;
    p1.showInfo();
    p2.showInfo();
    Person p3 = p2 = p1;
    p3.showInfo();

    return;
}