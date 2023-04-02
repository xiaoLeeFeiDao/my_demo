/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2022-11-01 00:29:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-03-05 01:27:36
 * @FilePath: /test_win11/cpp_learn/game1.cpp
 * @Description:
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "game1.h"
using namespace std;
// 在头文件中定义的有名命名空间所有包含的变量声明，必须在某个使用的.cpp中有定义
int LOL::m_stuAge = 10;
int LOL::m_TeacherAge = 20;

static void game1MyPrint()
{
    //  这里的m_LOL_static_Age必须前面加作用域，由于该全局静态函数并未指定LOL的作用域，而m_LOL_static_Age在LOL的命名空间下
    // cout << "in game1MyPrint静态全局函数的m_LOL_static_Age = " << m_LOL_static_Age << endl; // 报错
    cout << "in game1 MyPrint静态全局函数的m_LOL_static_Age = " << LOL::m_LOL_static_Age << endl; // OK
}

void LOL::goAtk()
{
    cout << "LOL goAtk" << endl;
    // LOL::m_LOL_static_Age = 24;
    // 不管上句是否引用了m_LOL_static_Age，这里打印时也都可以不加作用域,由于goAtk方法已经指定了作用域
    cout << "in game1.cpp:有名的命名空间 m_LOL_static_Age = " << m_LOL_static_Age << endl;
    game1MyPrint();
    cout << "in game1.cpp:匿名命名空间 m_C = " << m_C << endl;

    MyPrint();

    return;
}