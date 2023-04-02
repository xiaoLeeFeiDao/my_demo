/*
 * @Description: 指针的引用
 * @Author: stone
 * @Date: 2020-01-29 14:51:28
 * @LastEditTime : 2020-01-30 17:27:50
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

struct Person {
    int age;
};

/**
 * @description:c语言中的外部调用前定义空指针，内部申请空间
 * @param :
 * @return:
 */
static void allocSpace01(Person **p)
{
    *p = (Person *)malloc(sizeof(Person));
    (*p)->age = 10;
    cout << "Person p's age is " << (*p)->age << endl;
    return;
}

/**
 * @description:
 * @param :
 * @return:
 */
static void allocSpace02(Person *&p)
{
    p = (Person *)malloc(sizeof(Person));
    p->age = 20;
    cout << "Person p's age is " << p->age << endl;
    return;
}

/**
 * @description:
 * @param :
 * @return:
 */
void Test12()
{
    Person *p = nullptr;
    allocSpace01(&p);
    if (p != nullptr) {
        free(p);
    }

    allocSpace02(p);
    if (p != nullptr) {
        free(p);
    }
    return;
}
