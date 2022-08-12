/*
 * @Description: new运算符
 * @Author: stone
 * @Date: 2020-02-08 12:36:22
 * @LastEditTime : 2020-02-09 13:39:50
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    Person()
    {
        cout << "自定义无参构造" << endl;
    }
    Person(int age)
    {
        m_Age = age;
        cout << "有参构造" << endl;
    }
    Person(const Person &p)
    {
        m_Age = p.m_Age;
        cout << "拷贝构造" << endl;
    }
    ~Person()
    {
        cout << "析构" << endl;
    }

    // private:
    int m_Age;
};
/**
 * @description: new和malloc的区别：
 * 1、new是运算符，malloc是库函数
 * 2、malloc返回的是void* new返回的是新对象指针
 * 3、malloc需要判断是否分配成功，new是内部做了malloc的判空、类型转换等操作
 * 4、malloc不调用构造函数，new会调用默认构造函数
 * 5、malloc对应的释放是free，而new对应的是delete
 * 6、注意事项：
 *  不要用void*来接收一个new出来的对象，原因是不能释放，除非强制转换为对应类型
 * @param :
 * @return:
 */
void Test23()
{
    // Person p1; //开辟到栈上
    // Person p2(18);
    // Person p3(p2);

    //使用new在堆区分配内存
    Person *p1 = new Person;
    Person *p2 = new Person(18);
    Person *p3 = new Person(*p2);
    delete p1;
    delete p2;
    delete p3;

    //利用new来创建数组
    int *pArr = new int[20];
    char *pStr = new char[20];
    cout << "pArr[0] = " << pArr[0] << endl;
    cout << "pStr[0] = " << pStr[0] << endl;

    Person *pUser = new Person[10]; //注意：利用new在堆区创建对象数组，类中必须有默认构造函数，不然无法创建
    delete[] pUser;                 //如果释放的是数组，需要在delete后加[]，原因是如果对象是数组，内存中会默认在数组的前面有个数组的个数
    // 如果是在栈区创建对象数组，可以使用有参构造来创建对象，可以不一定需要默认构造函数
    Person pUser2[3] = {Person(10), Person(20), Person(30)};
    return;
}