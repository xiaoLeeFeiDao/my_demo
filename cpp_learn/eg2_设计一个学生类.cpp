/*
 * @Description: 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
 * @Author: stone
 * @Date: 2020-01-31 13:03:50
 * @LastEditTime : 2020-01-31 17:34:11
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    /* data */
public:
    string m_Name;
    int m_ID;
    void setName(string inputName)
    {
        m_Name = inputName;
    }
    void setID(int inputID)
    {
        m_ID = inputID;
    }
    void showStudentInfo(Student stuInfo)
    {
        cout << "Name is " << stuInfo.m_Name << endl;
        cout << "ID is " << stuInfo.m_ID << endl;
    }
};
/**
 * @description:
 * @param :
 * @return:
 */
void TestEg2()
{
    Student stu;
    stu.setName("lilei");
    stu.setID(9527);
    stu.showStudentInfo(stu);
    return;
}