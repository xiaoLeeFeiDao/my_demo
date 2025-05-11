/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2022-11-01 00:29:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-03-05 07:57:44
 * @FilePath: /test_win11/cpp_learn/game1.h
 * @Description:
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#ifndef _GAME1_H
#define _GAME1_H
#include <iostream>
using namespace std;
// 1、命名空间 用途：解决命名冲突
// 2、命名空间下 可以存放 变量、函数、结构体、类 也可以嵌套包含其他命名空间

namespace LOL
{
    // 头文件中的有名命名空间下的全局变量必须使用extern关键字修饰，否则如果多个不同的.cpp文件同时包含该头文件时会在链接时引发重复定义报错
    extern int m_stuAge;
    // 头文件中的有名命名空间下的静态变量，无需关键词修饰，多文件使用时，不会引发重复定义等编译报错
    static int m_LOL_static_Age;
    // 头文件中的有名命名空间下的函数必须是声明，实现需在.cpp中，否则如果多个不同的.cpp文件同时包含该头文件时会在链接时引发重复定义报错
    void goAtk();
    struct Person {
        char *name;
    };
    class Student {
        char *stuName;
    };
}

// 3、命名空间必须声明在全局作用域下
static void func()
{
    // 这里会报错，因为该命名空间不在全局作用域下
    // namespace B {

    // }
}

// 4、命名空间是开放的，可以随时向命名空间下添加新成员，
namespace LOL {
    extern int m_TeacherAge;
    namespace LOL_Ex
    {
        class Teacher {
            int m_Age;
        };
    }
}
static int g_static_F;
// 5、命名空间可以匿名
namespace
{
    // 匿名命名空间下的变量，不需要加extern修饰，因为匿名命名空间下的变量 为全局变量
    int m_C = 50;
    // 匿名命名空间下的静态全局变量
    static int m_D = 100;
    // 匿名命名空间下的函数，也不一定非要在.cpp中定义，在头文件中声明，因为匿名命名空间下的变量视为全局函数
    void MyPrint()
    {
        static int m_E = 20;
        m_D++;
        cout << "MyPrint call 匿名命名空间下的静态全局变量 m_D = " << m_D << endl;
        m_E++;
        cout << "MyPrint call 匿名命名空间下的静态局部变量 m_E = "<< m_E << endl;
        g_static_F++;
        cout << "MyPrint call 不在匿名命名空间下的未初始化的静态全局变量g_static_F = " << g_static_F << endl;
    }
}

// 6、命名空间可以起别名
namespace VeryLongName
{
    extern int m_G;
}
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif
#endif // _GAME1_H