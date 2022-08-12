/*
 * @Description: 构造函数的调用规则
 * @Author: stone
 * @Date: 2020-02-05 14:10:32
 * @LastEditTime : 2020-02-10 18:33:15
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
struct student {
    char m_Name[20];
    int m_Age;
    bool m_Istall;
};
class teacher {
public:
    char *getName()
    {
        return m_Name;
    }
    int getAge()
    {
        return m_Age;
    }
    bool getTall()
    {
        return m_Istall;
    }

private:
    char m_Name[20];
    int m_Age;
    bool m_Istall;
};
class myClass {
public:
    // myClass()
    // {
    //     cout << "无参构造函数" << endl;
    // }
    // myClass(int a)
    // {
    //     m_a = a;
    //     cout << "有参构造函数(int a)" << endl;
    // }
    // myClass(const myClass& c)
    // {
    //     m_a = c.m_a;
    //     cout << "拷贝构造函数" << endl;
    // }
    ~myClass()
    {
        cout << "析构函数" << endl;
    }
    int getMa()
    {
        return m_a;
    }
    int getMb()
    {
        return m_b;
    }
    char *getMstr()
    {
        return m_str;
    }
    char getMc()
    {
        return m_c;
    }

    student m_stu;
    teacher m_teah;

private:
    int m_a;
    int m_b;
    char m_str[16];
    char m_c;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test19()
{
    // 1、系统默认提供三个构造函数，默认构造函数，析构函数，拷贝构造函数(简单的值拷贝)
    //如果调用默认构造函数，把拷贝构造函数注释掉，系统会走自己的一套拷贝构造函数(简单的值拷贝)
    // myClass c1; //初始化一个无参构造函数
    // myClass cl1(c1); //如果将myCLass类中的所有自定义构造函数注释掉(不包括析构函数)，cl1的成员m_a仍然会有值，成员的值为系统随机分配
    // //通过以下验证发现：如果使用一个默认无参构造函数作为系统默认拷贝函数的入参，则所有成员的属性都是系统随机分配的数值
    // cout << "cl1 a " << cl1.getMa() << endl;
    // cout << "cl1 b " << cl1.getMb() << endl;
    // cout << "cl1 str " << cl1.getMstr() << endl;
    // cout << "cl1 c " << cl1.getMc() << endl;
    // cout << "cl1 stu age " << cl1.m_stu.m_Age << endl;
    // cout << "cl1 stu name " << cl1.m_stu.m_Name << endl;
    // cout << "cl1 stu tall " << cl1.m_stu.m_Istall << endl;
    // cout << "cl1 teah age " << cl1.m_teah.getAge() << endl;
    // cout << "cl1 teah Name " << cl1.m_teah.getName() << endl;
    // cout << "cl1 teah tall " << cl1.m_teah.getTall() << endl;

    // 2、如果我们提供了有参构造函数，那么系统不会提供默认构造函数了，但是仍然会提供拷贝构造函数
    //证明方法是：将myClass中的自定义无参构造函数和自定义拷贝构造函数注释，只保留有参构造时，下一行的语句编译不通过
    // myClass c2;
    ////但是下一行为系统提供的拷贝构造函数
    // myClass c21(10);
    // myClass c22(c21);
    // cout << "c22 m_a " << c22.getMa() << endl;

    // 3、如果我们提供了拷贝构造函数，那么系统将不会提供默认和有参构造函数了
    //证明方法:将myCLass中的自定义构造函数和自定义默认构造函数注释掉,那么实例化有参和无参对象都会失败
    // myClass c3;
    // myClass c31(10);

    return;
}