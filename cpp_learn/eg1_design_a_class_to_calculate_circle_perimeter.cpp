/*
 * @Description: 设计一个类，求圆的周长
 * @Author: stone
 * @Date: 2020-01-31 07:44:21
 * @LastEditTime : 2020-01-31 09:22:49
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

const double PI = 3.14;
class Circle {
public: //公共作用域
    //类中的函数，称为成员函数，或者成员方法
    double calculatePerimeter()
    {
        return 2 * PI * m_R;
    }
    void setRadius(int inputRadius)
    {
        m_R = inputRadius;
    }
    int GetRadius()
    {
        return m_R;
    }
    int m_R;
};
/**
 * @description:
 * @param :
 * @return:
 */
void TestEg1()
{
    Circle c1; //创建一个对象，称为实例化对象
    // c1.m_R = 10;
    c1.setRadius(10);
    // cout << "circle's radius: " << c1.m_R << endl;   //可通过类方法实现获取对象的属性
    cout << "circle's radius: " << c1.GetRadius() << endl;
    cout << "circle's perimeter: " << c1.calculatePerimeter() << endl;
}