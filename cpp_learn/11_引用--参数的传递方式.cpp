/*
 * @Description: 参数的传递方式
 * @Author: stone
 * @Date: 2020-01-27 19:53:29
 * @LastEditTime : 2020-02-10 11:01:58
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

/**
 * @description:
 * @param : 
 * @return: 
 */
static void mySwip01(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
 * @description: 
 * @param : 
 * @return: 
 */
static void mySwip02(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

/**
 * @description: 
 * @param : 
 * @return: 
 */
static void mySwip03(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

/**
 * @description: 引用的注意事项：
 *      1、不要返回局部变量的引用，由于局部变量在其作用域内属于栈区内存，生命周期结束后栈区内存会被系统回收，再使用属于非法操作内存，
 *          除非返回的是静态变量的引用。
 *      2、如果函数的返回值是一个引用(静态变量的引用，其他返回的引用均为非法返回)，那么这个函数可以作为左值进行运算。
 * @param : 
 * @return: 
 */
static int& myFunc()
{
    static int a = 10;
    return a;
}
static int TestReturn()
{
    int& ret = myFunc();
    cout << "ret = " << ret << endl; //有可能编译器优化结果，保存了之前的数据，但此处已属于非法内存。
    cout << "ret = " << ret << endl;
    cout << "ret = " << ret << endl;
    myFunc() = 100;
    cout << "myFun() as left value:ret = " << ret << endl;
    return 0;
}
/**
 * @description: 
 * @param : 
 * @return: 
 */
void Test11()
{
    int a = 10;
    int b = 20;
    mySwip01(a, b); //值传递
    mySwip02(&a, &b); //地址传递
    mySwip03(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    TestReturn();
    return;
}
