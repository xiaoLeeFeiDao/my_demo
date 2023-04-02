/*
 * @Description: 数组类的封装
 * @Author: stone
 * @Date: 2020-02-12 11:28:27
 * @LastEditTime : 2020-02-16 21:54:08
 * @LastEditors  : stone
 */

#include "eg6_package_array_class.h"

MyArray::MyArray()
{
    cout << "默认构造函数" << endl;
    this->m_Count = 100;
    this->m_Size = 0;
    m_Arry = new int[this->m_Count];
}
MyArray::MyArray(int count)
{
    cout << "有参构造函数" << endl;
    this->m_Count = count;
    this->m_Size = 0;
    m_Arry = new int[this->m_Count];
}
MyArray::MyArray(const MyArray& arr)
{
    cout << "拷贝构造函数" << endl;
    this->m_Count = arr.m_Count;
    this->m_Size = arr.m_Size;
    this->m_Arry = new int[arr.m_Count];
    for (int i = 0; i < m_Size; i++) {
        this->m_Arry[i] = arr.m_Arry[i];
    }
}
void MyArray::pushBack(int data)
{
    this->m_Arry[this->m_Size] = data;
    this->m_Size++;
}
void MyArray::setDataByPosition(int index, int data)
{
    this->m_Arry[index] = data;
}
int MyArray::getDataByPositon(int index)
{
    return this->m_Arry[index];
}
int MyArray::getArrSize()
{
    return this->m_Size;
}
int MyArray::getArrCount()
{
    return this->m_Count;
}
int& MyArray::operator[](int index)
{
    return this->m_Arry[index];
}
void MyArray::display()
{
    cout << "m_Count: " << m_Count << endl;
    cout << "m_Size: " << m_Size << endl;
    cout << "value is " << endl;
    for (int i = 0; i < m_Size; i++) {
        cout << " " << m_Arry[i] << endl;
    }
}
MyArray::~MyArray()
{
    cout << "析构函数" << endl;
    if (this->m_Arry != nullptr) {
        delete[] this->m_Arry;
        this->m_Arry = nullptr;
    }
}
/**
 * @description: 
 * @param : 
 * @return: 
 */
void TestEg6()
{
    MyArray arr1(5);
    arr1.pushBack(0);
    arr1.pushBack(1);
    arr1.pushBack(2);
    arr1.pushBack(3);
    arr1.pushBack(4);
    MyArray arr2(arr1);
    arr2.setDataByPosition(4, 1000);
    // arr2.display();

    // (&arr2)[3] = 100;   //非法，会出现core dumped
    // arr2.m_Arry[8] = 98; //私有属性无法修改
    // arr2.display();

    MyArray* pArr = new MyArray(20);
    delete pArr;

    //使用setDataByPosition过于繁琐，采用数组方式，需要使用[]运算符重载
    arr2[4] = 99;
    arr2[3] = 88889;
    arr2.display();
    return;
}