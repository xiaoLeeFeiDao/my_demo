/*
 * @Description: 常函数和常对象
 * @Author: stone
 * @Date: 2020-02-11 13:52:21
 * @LastEditTime : 2020-02-14 21:20:35
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
        m_Age = 0;
        m_Name = "";
    }
    //常函数
    void showInfo() const
    {
        cout << "m_Age = " << this->m_Age << endl;
        // this相当于Student const *this，是一个指针常量，即this中存放的地址是一个常量，不可以对其进行修改。
        //  this = nullptr; //该操作是不成功的，其值为一个常量，不允许修改
        //但是this指针指向的内存里面的数值数据是可以修改的
        //  this->m_Age = 100;

        //为了防止this指针指向的内存里面的数值数据也不能修改，则需要使用常函数，类似于const Student const *this，使用方法是
        // 在void showInfo() 函数的后面加const，这样，这个成员函数就不可以修改类中的成员属性了

        // 但是如果常函数中的某些属性想让其可以进行修改，则需要加mutable关键字来修饰该属性，例如m_Name
        m_Name = "lintao";

        return;
    }

    void display()
    {
        cout << "m_Age = " << m_Age << endl;
        cout << "m_Name = " << m_Name << endl;
        cout << "m_ID = " << m_ID << endl;
        cout << "m_Record = " << m_Record << endl;
        return;
    }

    void setInfo(string name, int age)
    {
        m_Age = age;
        m_Name = name;
        return;
    }
    
    Student &getInfo()
    {
        return *this;
    }
    void displayInfoConstObj() const
    {
        cout << "m_Age = " << m_Age << endl;
        cout << "m_Name = " << m_Name << endl;
        cout << "m_ID = " << m_ID << endl;
        cout << "m_Record = " << m_Record << endl;
        return;
    }
    void setInfoConstObj(const string name) const
    {
        m_Name = name;
        return;
    }

    // void setInfoConstObj2(const string name, int age) const  //编译报错，只能修改mutable修饰的成员属性，不能修改其他成员属性
    // {
    //     m_Name = name;
    //     m_Age = age;
    //     return;
    // }
    int m_ID;
    mutable int m_Record;

private:
    int m_Age;
    mutable string m_Name;
};
/**
 * @description:
 * @param :
 * @return
 */
void Test30()
{
    Student stu;
    //调用常函数
    stu.showInfo();
    stu.display();

    //常对象，如果用户没有提供默认构造，不允许定义const常对象
    const Student stu2;
    // 常对象不可以修改内部的属性
    // stu2.m_ID = 159921;
    // 常对象不可以调用普通的成员函数，而常对象要求是不可以修改内部的属性，因此不配套
    // stu2.setInfo("hanmeimei", 19);
    // stu2.display();

    // 常对象可以修改mutable修饰的成员属性(如果是私有的成员属性，可以通过常函数)
    // 修改public权限的成员属性
    stu2.m_Record = 98;
    stu2.displayInfoConstObj();

    // 修改private权限的成员属性
    stu2.setInfoConstObj("hanmeimei");
    // 只能修改mutable修饰的成员属性，不能修改其他成员属性
    // stu2.setInfoConstObj2("lintao",24);

    stu2.displayInfoConstObj();
    return;
}