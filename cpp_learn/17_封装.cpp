/*
 * @Description: 封装
 * @Author: stone
 * @Date: 2020-02-02 14:10:50
 * @LastEditTime : 2020-02-02 17:34:21
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string m_Name;
    int m_Age;
    void eatSomethings(Person *p)
    {
        cout << p->m_Name << " eat peaple's food" << endl;
        return;
    }
};
class Dog {
public:
    string m_Name;
    int m_Age;
    void eatSomethings(Dog *d)
    {
        cout << d->m_Name << " eat dog's food" << endl;
        return;
    }
};
/**
 * @description: c++语言下的封装特点：
 * 1、c++重视类型限定
 * 2、将属性和行为封装到一起
 * 3、有权限保护：public、private、protect
 * 封装注意：
 * 1、尽量将属性设置为私有private，这样属性就有可读、可写、可读可写、不可读不可写等状态
 * @param :
 * @return:
 */
void Test17()
{
    Person p;
    p.m_Name = "Tom";
    p.eatSomethings(&p);

    Dog d;
    d.m_Name = "xiaobei";
    d.eatSomethings(&d);
    // d.eatSomethings(&p); //如果是纯c代码，并在c语言编译器下，这里是可以成功调用的，结果就是人吃狗粮^-^，说明c语言对类型的限定并不严谨

    return;
}