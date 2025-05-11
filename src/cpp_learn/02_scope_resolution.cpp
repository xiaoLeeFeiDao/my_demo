/*
 * @Author: stone
 * @Date: 2022-02-20 18:05:09
 * @LastEditors: XiaoLeeFeiDao XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 22:33:57
 * @FilePath: /my_projects/src/cpp_case/src/02_双冒号作用域运算�?.cpp
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
    cout << "局部攻击力" << g_atk << endl;
    // ::作用域运算::前面没有任何作用域情况下，代表使用全局作用
    cout << "全局攻击力：" << ::g_atk << endl;
}

void Test02()
{
    LocalTest01();
}