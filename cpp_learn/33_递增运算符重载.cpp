/*
 * @Description: 递增运算符重载
 * @Author: stone
 * @Date: 2020-02-13 14:55:46
 * @LastEditTime : 2020-02-14 13:39:04
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
class MyInter {
    friend ostream &operator<<(ostream &cout, MyInter &obj);
    friend ostream &operator<<(ostream &cout, MyInter obj);

public:
    MyInter()
    {
        this->m_Num = 0;
    }
    MyInter &operator++()
    {
        ++this->m_Num;
        return *this;
    }
    MyInter operator++(int)
    {
        MyInter tmp = *this;
        this->m_Num++;
        return tmp;
    }

private:
    int m_Num;
};
ostream &operator<<(ostream &cout, MyInter &obj)
{
    cout << "m_Num = " << obj.m_Num;
    return cout;
}
ostream &operator<<(ostream &cout, MyInter obj)
{
    cout << "m_Num = " << obj.m_Num;
    return cout;
}
/**
 * @description:
 * @param :
 * @return:
 */
void Test33()
{
    ////目前的操作是模仿下面代码实现
    int a = 0;
    cout << ++(++a) << endl;
    cout << a << endl;

    ////但是如果operator++返回的不是引用，而是一个被调用的函数退出时复制出来的另一个对象，则下面代码不会等同于上面的关于a自增的代码
    ////所以，被调用函数定义的返回值一定要是引用，表示返回的一直是一个数据，在链式编程中返回引用可以一直对一个数据进行操作`
    MyInter obj;
    // cout << ++(++obj) << endl;
    cout << obj++ << endl;

    return;
}