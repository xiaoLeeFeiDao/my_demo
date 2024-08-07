#include <iostream>
#include <string>
#include "cpp_learn_inner.h"
using namespace std;

void Test10()
{
    int a = 10;
    int &b = a; // 用途：给内存起别名 语法：type &别名 = 原名
    b = 20;
    cout << "a = " << a << endl;
    int d = 30;
    b = d; // 赋值操作
    cout << "a = " << a << ", b = " << b << ", d = " << d << endl;
    // 1、引用必须要初始化
    // int &c; // 这种不初始化的方式是 不允许的，编译会报错

    // 2、一旦初始化后，就不可以修改指向了
    // &b = d;

    // 3、建立对数组的引用
    int arr[10];
    int (&pArr)[10] = arr;
    for (size_t i = 0; i < 10; i++) {
        pArr[i] = i;
    }

    for (int i = 10 - 1; i >= 0; i--) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

}