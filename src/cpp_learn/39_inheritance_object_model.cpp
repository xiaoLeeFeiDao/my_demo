/*
 * @Description: 继承中的对象模型
 * @Author: stone
 * @Date: 2020-03-13 14:37:27
 * @LastEditTime: 2020-03-13 15:30:03
 * @LastEditors: stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son : public Base {
public:
    int m_D;
};

/**
 * @description:
 * @param :
 * @return:
 */
void Test39()
{
    // 父类的私有属性子类也继承了，只是由于编译器隐藏了，因此访问不到
    // 所以计算这个子类的大小时，父类的12个字节(私有属性的大小也包含)，子类的4个字节，共16个字节
    cout << sizeof(Son) << endl;
    return;
}
