/*
 * @Description: 字符串类得封装
 * @Author: stone
 * @Date: 2020-02-18 15:14:36
 * @LastEditTime: 2020-02-28 12:59:35
 * @LastEditors: stone
 */
#include "eg7_package_string_class.h"

MyString::MyString()
{
    this->m_Str = nullptr;
    this->m_Size = 0;
}
MyString::MyString(const char* str)
{
    this->m_Str = new char[strlen(str) + 1];
    strcpy(this->m_Str, str);
    this->m_Size = strlen(this->m_Str);
}
MyString::MyString(const MyString& user)
{
    if (this->m_Str != nullptr) {
        delete[] this->m_Str;
        this->m_Str = nullptr;
    }
    strcpy(this->m_Str, user.m_Str);
    this->m_Size = strlen(this->m_Str);
}
istream& operator>>(istream& cin, MyString* user)
{
    if (user->m_Str != nullptr) {
        delete[] user->m_Str;
        user->m_Str = nullptr;
    }
    char buf[1024] = { 0 };
    cin >> buf;
    user->m_Str = new char[strlen(buf) + 1];
    strcpy(user->m_Str, buf);
    user->m_Size = strlen(user->m_Str);
    return cin;
}
void MyString::setInfo()
{
    cout << "please input string:" << endl;
    cin >> this;
}
void MyString::showInfo()
{
    cout << "m_Str = " << this->m_Str << endl;
    cout << "m_Size = " << this->m_Size << endl;
    return;
}
MyString::~MyString()
{
    if (this->m_Str != nullptr) {
        delete[] this->m_Str;
        this->m_Str = nullptr;
    }
}
/**
 * @description: 
 * @param : 
 * @return: 
 */
void TestEg7()
{
    // const char* pStr = "helloworld!";
    // MyString str(pStr);
    MyString str("helloworld!");
    str.showInfo();
    str.setInfo();
    str.showInfo();
    return;
}