/*Students
 * @Description: 加号运算符重载
 * @Author: stone
 * @Date: 2020-02-12 13:28:10
 * @LastEditTime : 2020-02-13 10:00:47
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Students {
    friend Students operator+(const Students &stu1, const Students &stu2);
    friend ostream &operator<<(ostream &cout, Students &stu);

public:
    Students();
    Students(string name, int age, int record);
    Students(const Students &stu);
    Students &getInfo();
    Students addObjCustom(const Students &stu);
    Students operator+(const Students &stu);
    void display();
    ~Students();

private:
    int m_Age;
    string m_Name;
    int m_Record;
};

Students::Students()
{
    m_Age = 0;
    m_Record = 0;
    m_Name = "";
}

Students::Students(string name, int age, int record)
{
    m_Age = age;
    m_Record = record;
    m_Name = name;
}

Students::Students(const Students &stu)
{
    m_Age = stu.m_Age;
    m_Record = stu.m_Record;
    m_Name = stu.m_Name;
}

void Students::display()
{
    cout << "name = " << this->m_Name << endl;
    cout << "age = " << this->m_Age << endl;
    cout << "record = " << this->m_Record << endl;
}

Students &Students::getInfo()
{
    return *this;
}

Students::~Students()
{
}

//自定义两个类相加
Students Students::addObjCustom(const Students &stu)
{
    Students tmp;
    tmp.m_Age = this->m_Age + stu.m_Age;
    tmp.m_Record = this->m_Record + stu.m_Record;
    tmp.m_Name = this->m_Name + stu.m_Name;
    return tmp;
}

//编译器给起了一个名字
Students Students::operator+(const Students &stu)
{
    Students tmp;
    tmp.m_Age = this->m_Age + stu.m_Age;
    tmp.m_Record = this->m_Record + stu.m_Record;
    tmp.m_Name = this->m_Name + stu.m_Name;
    return tmp;
}

//全局函数的符号重载
Students operator+(const Students &stu1, const Students &stu2)
{
    Students tmp;
    tmp.m_Age = stu1.m_Age + stu2.m_Age;
    tmp.m_Record = stu1.m_Record + stu2.m_Record;
    tmp.m_Name = stu1.m_Name + stu2.m_Name;
    return tmp;
}

ostream &operator<<(ostream &cout, Students &stu)
{
    cout << "m_Name = " << stu.m_Name << " m_Age = " << stu.m_Age << " m_Record = " << stu.m_Record;
    return cout;
}

/**
 * @description:
 * @param :
 * @return:
 */
void Test32()
{
    Students stu0;
    Students stu1("stone", 18, 100);
    Students stu2 = stu0.addObjCustom(stu1);
    Students stu3 = stu1.addObjCustom(stu2);
    stu3.display();

    Students stu4 = stu3.operator+(stu2);
    stu4.display();
    //简化为
    Students stu5 = stu4 + stu0;
    stu5.display();

    ////全局函数重载
    Students stu6 = operator+(stu5, stu4);
    stu6.display();
    ////简化为
    Students stu7 = stu6 + stu5;
    stu7.display();

    ////左移运算符重载
    cout << stu7 << endl;
    return;
}