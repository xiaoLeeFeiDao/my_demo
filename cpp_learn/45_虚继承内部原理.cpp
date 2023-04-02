/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-04-02 10:52:28
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 11:17:59
 * @FilePath: /my_demo/cpp_learn/45_虚继承内部原理.cpp
 * @Description: 
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "cpp_learn_inner.h"
#include <iostream>

using namespace std;
class animal {
public:
    int m_Age;
};

class Sheep : virtual public animal
{
};

class Tuo : virtual public animal
{
};

class SheepTuo : public Sheep, public Tuo
{
};

void Test45()
{
    SheepTuo st;
    st.m_Age = 100;
    cout << sizeof(st) << endl;
    cout << "你好 世界" << endl;
    // 找到Sheep的偏移量操作
    // cout << *(int *)((int *)*(int *)&st + 1) << endl;
    cout << *(uintptr_t *)((uintptr_t *)*(uintptr_t *)&st + 1) << endl;
    return;
}