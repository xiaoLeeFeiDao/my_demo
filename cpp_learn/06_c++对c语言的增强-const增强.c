/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-03-25 22:46:48
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 11:16:42
 * @FilePath: /my_demo/cpp_learn/07_c++对c语言的增强-const增强.c
 * @Description:
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "cpp_learn_inner.h"
#include <stdio.h>
const int g_A = 100;
static void LocalTest01()
{
    (void)g_A;
    // g_A = 200; // 全局const修饰的变量，受常量区保护不可以直接修改

    // int *p = &g_A; // 虽然可以通过指针来间接的修改，但是在运行时就会报错
    // *p = 230;

    const int l_B = 20; // 局部const修饰的变量可以通过指针间接的修改，因此局部const修饰的变量在c语言中也称为伪常量
    // l_B = 23; // 局部const修饰的变量也是不可以直接修改
    int *ptr = (int *)&l_B; // 但是可以通过指针间接修改,可能不加强转会有告警
    *ptr = 35; // 修改后运行时不会报错
    printf("l_B = %d\n", l_B);
    printf("*ptr = %d\n", *ptr);
    return;
}
void Test06()
{
    LocalTest01();
    return;
}