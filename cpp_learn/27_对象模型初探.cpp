/*
 * @Description: 对象模型初探
 * @Author: stone
 * @Date: 2020-02-10 11:35:22
 * @LastEditTime : 2020-02-10 17:25:48
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
class Teacher {
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test27()
{
    //空类的大小为1：空类也是可以实例化对象的，每个对象在内存中都应该有一个独一无二的地址
    // Teacher p[10] p[1] p[0]
    //类中的成员方法并未算入类的内存大小
    //类中的静态成员属性也不属于类的内存大小，编译阶段已分配好内存
    //类中的静态成员函数也不属于类的内存大小
    //类中的非静态成员变量才计算类的大小，成员属性按照内存对齐计算,根据对齐模数计算
    cout << sizeof(Teacher) << endl;
    return;
}