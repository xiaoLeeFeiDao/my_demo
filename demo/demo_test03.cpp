#include "demo_inner.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Person {
public:
    Person(): name("stone"), age(24),heigh(189),weight(149),alias("11dao") {
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