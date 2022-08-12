/*
 * @Description: 常量的引用
 * @Author: stone
 * @Date: 2020-01-30 17:28:56
 * @LastEditTime : 2020-01-31 08:14:47
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

/**
 * @description: 常量引用的非正常使用场景
 * @param :
 * @return:
 */
static void TestExample01()
{
    // int& ref = 10; // 此处为错误语法，因为引用必须引用一块合法的内存地址空间，堆区或者栈区，不能为常量区的地址。
    const int &ref = 10; //但是引用前加上const修饰，可合法编译，这是由于编译器作了优化：int temp = 10;const int& ref = temp;
    //即该处定义的常量保护引用被系统随机申请的一块栈区临时地址空间赋值了，这块受保护栈区地址所指向的地址不允许直接被修改。即下句语法错误
    // ref = 1000; //上一句定义后，这里不可以对该引用重新赋值，因为该引用的地址指向的是常量区，但是可以通过重新定义一个指针变量来修改
    int *pRef = (int *)&ref;
    *pRef = 200;
    cout << "ref = " << ref << endl;
}

/**
 * @description:常量引用的正常使用场景
 * @param :
 * @return:
 */
// static void showValue(int& a) //该处入参使用引用或者使用普通int类型变量，运行结果相同，使用引用的好处是未在栈区拷贝新数据，节省空间。但是有弊端：容易误操作
static void showValue(const int &a)
{
    // a = 200; //此处容易误操作,如果此处修改了a的值，对应的外面的a的值也会被修改，而编译时并不会报错，为避免此类误操作，需使用常量引用
    cout << "a = " << a << endl;
    return;
}

static void TestExample02()
{
    int a = 100;
    showValue(a);
    cout << "TestExample02: a = " << a << endl;
    return;
}

/**
 * @description:
 * @param :
 * @return:
 */
void Test13()
{
    TestExample01();
    TestExample02();
    return;
}
