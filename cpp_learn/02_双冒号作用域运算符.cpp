/*
 * @Author: stone
 * @Date: 2022-02-20 18:05:09
 * @LastEditors: stone
 * @LastEditTime: 2022-03-13 10:41:33
 * @FilePath: /my_projects/src/cpp_case/src/02_双冒号作用域运算符.cpp
 * @Description:
 *
 * Copyright (c) 2022 by stone/lldao, All Rights Reserved.
 */
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;
int g_atk = 1000;

void LocalTest01()
{
    int g_atk = 2000;
    cout << "局部攻击力：" << g_atk << endl;
    // ::作用域运算符 当::前面没有任何作用域情况下，代表使用全局作用域 
    cout << "全局攻击力：" << ::g_atk << endl;
}

void Test02()
{
    LocalTest01();
}