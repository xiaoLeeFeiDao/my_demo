/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-04-02 10:44:33
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 11:17:27
 * @FilePath: /my_demo/demo/demo_test03.cpp
 * @Description: 
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
#include "demo_inner.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Person {
public:
    Person(): name("stone"), age(24),height(189),weight(149),alias("11dao") {
    }
    char name[24];
    int age;
    int height;
    int weight;
    char alias[24];
};

class TempPerson {
    char *name;
    int nameLen;
    int age;
    int height;
    int weight;
    char *alias;
};

void DemoTest03()
{
    cout << "hello test03" << endl;
    Person p;

    return;
}