/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-04-02 10:52:28
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 10:55:02
 * @FilePath: /test_win11/cpp_learn/45_��̳��ڲ�ԭ��.cpp
 * @Description: 
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "cpp_learn_inner.h"
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