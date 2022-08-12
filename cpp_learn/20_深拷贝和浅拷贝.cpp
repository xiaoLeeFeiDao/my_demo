/*
 * @Description: 深拷贝和浅拷贝
 * @Author: stone
 * @Date: 2020-02-05 17:39:39
 * @LastEditTime : 2020-02-08 17:36:12
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <cstring>
#include <iostream>
using namespace std;

class Person {
public:
    Person(const char *name, int age)
    {
        cout << "Person 有参函数的调用" << endl;
        m_Name = (char *)malloc(strlen(name) + 1); // strlen函数如果入参是char*,则需包含头文件为<cstring>
        memset(m_Name, 0, sizeof(strlen(m_Name)));
        strcpy(m_Name, name);
        m_Age = age;
    }
    int getAge()
    {
        return m_Age;
    }
    char *getName()
    {
        return m_Name;
    }
    Person(const Person &p)
    {
        m_Name = (char *)malloc(strlen(p.m_Name) + 1);
        memset(m_Name, 0, sizeof(strlen(m_Name)) + 1);
        strcpy(m_Name, p.m_Name);
        m_Age = p.m_Age;
    }
    void showInfo()
    {
        cout << "m_Name: " << m_Name << " m_Age: " << m_Age << endl;
        return;
    }
    ~Person()
    {
        cout << "Person 析构函数的调用" << endl;
        if (m_Name != NULL) {
            free(m_Name);
            m_Name = NULL;
        }
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
void Test20()
{
    //    Person p1("tom", 18);
    //    p1.showInfo();
    //    Person p11(p1); //当使用有参构造时，系统会默认提供一个拷贝构造函数(自己不需要实现)，但是该拷贝构造为浅拷贝，即只作了
    //    // 简单的值传递。如果成员属性中有指针，利用拷贝构造实例化对象时就会出现该对象含有指针的那个成员和有参构造对象的指针成员同时指向
    //    // 同一块地址空间，这样就会在析构的时候出现doublefree，因此，我们需要对有malloc空间的成员属性，在拷贝构造时采用自定义的拷贝构造
    //    // 对有参构造对象中malloc的成员，在自定义拷贝构造中重新malloc空间。
    //    p11.showInfo();
    return;
}
