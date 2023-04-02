/*
 * @Description: 函数的默认参数及占位参数
 * @Author: stone
 * @Date: 2020-01-31 21:36:02
 * @LastEditTime : 2020-01-31 22:47:43
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @description: 函数的默认参数
 * @param :
 * @return:
 */
static int addFunc2Args(int a = 1, int b = 2)
{
    return a + b;
}
/**
 * @description: 如果参数列表中有一个位置有默认参数，那么从这个位置起，从左到右后面的参数必须都要有默认参数，否则会产生二义性
 * 前提条件是，调用时没有默认参数的参数必须有参数传入
 * @param :
 * @return:
 */
static int addFunc3Args(int a = 1, int b = 2, int c = 3) //参数全部有默认值，可以
// static int addFunc3Args(int a, int b = 2, int c = 3) //第一个参数没有设置默认值，可以
// static int addFunc3Args(int a = 1, int b, int c = 3) //第二个参数没有默认值，不可以
// static int addFunc3Args(int a = 1, int b = 2, int c) //第三个参数没有默认值，不可以
// static int addFunc3Args(int a, int b, int c = 4) //第1、2个参数没有默认值,可以
// static int addFunc3Args(int a, int b = 2, int c) //第1、3个参数没有默认值,不可以
// static int addFunc3Args(int a = 1, int b, int c) //第2、3个参数没有默认值,不可以
{
    return a + b + c;
}
/* 定义函数的默认参数时，声明时的默认参数和定义时的默认参数这两种方式，必须只有一个设置默认参数，避免二义性 */
static int TestDefine(int a = 2, int b = 3); //要么这里设置默认参数
static int TestDefine(int a, int b)          //要么这里设置默认参数，同上语句二选一
{
    return a + b;
}

// 函数的占位参数
/**
 * @description:
 * @param :
 * @return:
 */
// int getPosition(int a, int) //第二个参数未定义任何变量，只有一个数据类型，作用：目前没有用，后面学习到符号重载的时候会用到
static int getPosition(int a, int = 10) //针对调用格式为getPosition(2),见下方调用
{
    return a;
}
/**
 * @description:
 * @param :
 * @return:
 */
void Test15()
{
    TestDefine();
    cout << "2Args1: " << addFunc2Args() << endl;
    cout << "2Args1: " << addFunc2Args(10) << endl;
    cout << "2Args1: " << addFunc2Args(10, 20) << endl;
    cout << "3Args0: " << addFunc3Args() << endl;
    cout << "3Args1: " << addFunc3Args(4) << endl;
    cout << "3Args2: " << addFunc3Args(4, 5) << endl;
    cout << "3Args3: " << addFunc3Args(4, 5, 6) << endl;
    // getPosition(2, 1); //这里的第二个参数必须填入，不管填入的整形数据是多少，只是必须保证传入，除非定义该调用的该参数使用了默认值(这种情况则不能传入任何数值参数)该数值不起什么作用，不代表任何含义
    getPosition(2); //针对int getPosition(int a, int = 10)
    return;
}