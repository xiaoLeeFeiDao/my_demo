/*
 * @Description: 继承中的构造和析构
 * @Author: stone
 * @Date: 2020-03-13 15:31:30
 * @LastEditTime: 2020-03-13 15:39:00
 * @LastEditors: stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    Base()
    {
        cout << "Base的构造" << endl;
    }
    ~Base()
    {
        cout << "Base的析构" << endl;
    }

protected:
private:
};
class Son : public Base {
public:
    Son()
    {
        cout << "Son的构造" << endl;
    }
    ~Son()
    {
        cout << "Son的析构" << endl;
    }
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test40()
{
    // Base b;
    Son s;
    return;
}