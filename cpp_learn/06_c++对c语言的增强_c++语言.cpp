/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-03-06 07:15:03
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-03-06 08:01:18
 * @FilePath: /test_win11/cpp_learn/06_c++对c语言的增强_c++语言.cpp
 * @Description:
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "cpp_learn_inner.h"
#include <iostream>

using namespace std;

void Test06()
{
    cout << "Test06" << endl;

    // 5、 bool类型的增强，c语言下没有这个类型，在c++中bool类型为一个字节，代表真 true 和假 false
    bool flag = false;
    cout << "edit before flag = " << flag << endl;
    flag = true;
    cout << "edit after flag = " << flag << endl;
    cout << "sizeof(flag) = " << sizeof(flag) << endl;
}