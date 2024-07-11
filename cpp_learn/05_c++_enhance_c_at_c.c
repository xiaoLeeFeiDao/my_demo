/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-03-06 07:14:22
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-03-25 22:31:36
 * @FilePath: /test_win11/cpp_learn/05_c++对c语言的增强_c语言.c
 * @Description:
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cpp_learn_inner.h"
#define COMPILE_LEVEL 0
#define SINGLE_MAIN 0
#ifdef __cplusplus
extern "C" {
#endif

#if COMPILE_LEVEL
// 1、全局变量检测增强 c语言允许全局变量重复定义
int a;
int a = 10;

// 2、函数检测增强 c语言没有写返回值、没有写形参类型可以编译通过
GetRectS(w, h)
{
    // return w + h; // 就算不返回c语言编译器也可以通过
}

// 3、类型转换检测增强
void LocalTest03()
{
    // 未对malloc内存进行类型强制转换，但是c语言不会报错
    char *p = malloc(64);
    if (p != NULL)
    {
        free(p);
    }
}

// 4、struct增强，c++中可以在声明时不用加struct
struct Person {
    int age;
    // 不允许放函数,C++语言下，结构体中可以放函数
    // void Func();
};

// 5、 bool类型的增强，c语言下没有这个类型，在c++中bool类型为一个字节，代表真 true 和假 false

// 6、三目运算符增强
static void LocalTest01()
{
    int a = 10;
    int b = 20;
    printf("ret = %d\n", a > b ? a : b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // 在c语言下 编译报错 因为在c语言下三目运算符返回的是值，在c++语言下三目运算符返回的是变量
    // a > b ? a : b = 100;

    // 如何在c语言下实现？
    *(a > b ? &a : &b) = 100;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}
#endif
void Test0502()
{
#if COMPILE_LEVEL
    // 2.1、传参个数不规范，在c语言中也可以编译通过
    GetRectS(10, 10, 10);
    LocalTest01();
#endif
}
#ifdef __cplusplus
}
#endif

#if SINGLE_MAIN
int main()
{
    Test0502();
    return 0;
}
#endif
