#include "demo_inner.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Person {
public:
    Person() { }
    Person(int inAge, int inHeight, int inWeight)
        : name("stone")
        , age(24)
        , height(189)
        , weight(149)
        , alias("11dao")
    {
        this->age = inAge;
        this->height = inHeight;
        this->weight = inWeight;
    }

    char name[24];
    int age;
    int height;
    int weight;
    char alias[24];
};

class TempPerson {
    char* name;
    int nameLen;
    int age;
    int height;
    int weight;
    char* alias;
};

typedef struct {
    char name[20];
} TestName;
typedef struct {
    char* dstName;
} DstName;

static TestName GetTestName()
{
    TestName person;
    memset(&person, 0, sizeof(TestName));
    strcpy(person.name, "stone");

    return person;
}

static void HandleArrayBuff(TestName person)
{
    DstName teacher;
    teacher.dstName = person.name;
    cout << teacher.dstName << endl;
    teacher.dstName = NULL;

    teacher.dstName = person.name;
}

void DemoTest03()
{
    cout << "hello test03" << endl;
    Person p1 = Person(18, 29, 32);
    TestName student = GetTestName();
    HandleArrayBuff(student);

    return;
}