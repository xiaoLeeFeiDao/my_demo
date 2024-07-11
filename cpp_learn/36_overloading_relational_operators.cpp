/*
 * @Description: 关系运算符重载
 * @Author: stone
 * @Date: 2020-02-15 19:49:43
 * @LastEditTime : 2020-02-16 22:13:07
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
        this->m_Name = "";
        this->m_Age = 0;
    }
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    Person(const Person &user)
    {
        this->m_Name = user.m_Name;
        this->m_Age = user.m_Age;
    }
    bool operator==(const Person &pUser)
    {
        // if(this->m_Name == pUser.m_Name && this->m_Age == pUser.m_Age){
        // return true;
        // }
        // return false;

        //上述简化为
        return (this->m_Name == pUser.m_Name && this->m_Age == pUser.m_Age);
    }
    void showInfo()
    {
        cout << "m_Name = " << this->m_Name << endl;
        cout << "m_Age = " << this->m_Age << endl;
        return;
    }
    ~Person()
    {
        ;
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
void Test36()
{
    Person p1("tom", 18);
    Person p2("tim", 18);
    if (p1 == p2) {
        cout << "p1 == p2" << endl;
        return;
    }
    cout << "p1 != p2" << endl;
    return;
}