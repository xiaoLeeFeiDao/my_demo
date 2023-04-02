/***
 * @Author: stone
 * @Date: 2020-04-04 22:29:02
 * @LastEditTime: 2020-05-01 23:04:04
 * @LastEditors: stone
 * @Description:
 * @FilePath: /server_frame/src/Test/eg7_package_string_class.h
 * @Copyright © 2000-2020 lldao9527@139.com All Rights Reserved.
 */
#ifndef _EG7_PACKAGE_STRING_CLASS_H
#define _EG7_PACKAGE_STRING_CLASS_H
#include "cpp_learn_inner.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
// #ifdef __cplusplus
// extern "C" {
// #endif
class MyString {
    friend istream &operator>>(istream &cin, MyString *user);

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &user);
    void showInfo();
    void setInfo();
    ~MyString();

private:
    char *m_Str;
    int m_Size;
};
// #ifdef __cplusplus
// }
// #endif
#endif // _EG7_PACKAGE_STRING_CLASS_H