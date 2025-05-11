/*
 * @
 * @Author: stone
 * @Date: 2020-02-15 19:34:50
 * @LastEditTime : 2020-02-15 19:40:36
 * @LastEditors  : stone
 */
#ifndef _EG6_PACKAGE_ARRAY_CLASS_H
#define _EG6_PACKAGE_ARRAY_CLASS_H
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
#ifdef __cplusplus
extern "C" {
#endif

using namespace std;
class MyArray {
public:
    MyArray();
    MyArray(int count);
    MyArray(const MyArray &arr);
    ////尾插
    void pushBack(int data);
    ////根据位置设置数据
    void setDataByPosition(int index, int data);
    ////根据位置获取数据
    int getDataByPositon(int index);
    //// []重载
    int &operator[](int index);
    ////获取数组大小
    int getArrSize();
    ////获取数组容量
    int getArrCount();
    void display();
    ~MyArray();

private:
    ////指向堆区的指针
    int *m_Arry;
    int m_Size;
    int m_Count;
};

#ifdef __cplusplus
}
#endif
#endif // _EG6_PACKAGE_ARRAY_CLASS_H