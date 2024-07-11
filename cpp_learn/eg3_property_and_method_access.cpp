/*
 * @Description: 设置一个person类-属性方法访问权限
 * @Author: stone
 * @Date: 2020-02-03 14:08:40
 * @LastEditTime : 2020-02-03 14:24:45
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string m_Name;
    int m_Age;

public:
    void initPerson()
    {
        string m_Name = "";
        m_Age = 0;
    }
    void setName(string name)
    {
        m_Name = name;
        return;
    }
    string getName()
    {
        return m_Name;
    }
    void setAge(int age)
    {
        if (age < 0 || age > 100) {
            cout << "set the age is wrong." << endl;
            return;
        }
        m_Age = age;
        return;
    }
    int getAge()
    {
        return m_Age;
    }
    void displayInfo()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
        return;
    }
};
/**
 * @description:
 * @param :
 * @return:
 */
void TestEg3()
{
    Person user;
    user.initPerson();
    user.setName("lilei");
    user.setAge(28);
    user.setAge(128);
    cout << user.getAge() << endl;
    cout << user.getName() << endl;
    user.displayInfo();
    return;
}