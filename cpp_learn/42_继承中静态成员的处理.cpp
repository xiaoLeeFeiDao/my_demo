/***
 * @Author: stone
 * @Date: 2020-03-22 20:21:29
 * @LastEditTime: 2020-03-22 20:28:38
 * @LastEditors: stone
 * @Description:
 * @FilePath: /server_frame/src/Test/42. 继承中静态成员的处理.cpp
 * @Copyright ? 2000-2020 lldao9527@139.com All Rights Reserved.
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    static int m_A; //共享数据，编译阶段分配内存，类内声明，类外初始化

protected:
private:
};
int Base::m_A = 10;
class Son : public Base {
public:
    static int m_A;

protected:
private:
};
int Son::m_A = 20;
/***
 * @description:
 * @param {type}
 * @return:
 */
void Test42()
{
    Son s;
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;

    return;
}