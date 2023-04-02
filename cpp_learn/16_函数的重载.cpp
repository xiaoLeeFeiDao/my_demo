/*
 * @Description： 函数的重载
 * @Author: stone
 * @Date: 2020-02-01 06:30:19
 * @LastEditTime : 2020-02-01 22:08:59
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    void sameNameFunc(string personName)
    {
        cout << "args in class: personName is " << personName << endl;
        return;
    }
};

static void sameNameFunc()
{
    cout << "no args" << endl;
    return;
}
static void sameNameFunc(int age)
{
    cout << "int type: age is " << age << endl;
    return;
}
static void sameNameFunc(string userName)
{
    cout << "string type: username is " << userName << endl;
    return;
}
static void sameNameFunc(int age, float heigh)
{
    cout << "age: " << age << " heigh: " << heigh << endl;
    return;
}
static void sameNameFunc(float heigh, int age) //顺序不同
{
    cout << "heigh: " << heigh << " age: " << age << endl;
    return;
}
static void sameNameFunc(float heigh, int age, string userName) //个数和顺序都不同
{
    cout << "username: " << userName << " heigh: " << heigh << " age: " << age << endl;
    return;
}

// static int sameNameFunc(int age)   //该处如果想成功定义，必须是对形参做个数、顺序或者参数类型这三种条件的构造，例如下句
static int sameNameFunc(double age)
{
    return (int)age;
}

/**
 * @description:
 * @param :
 * @return:
 */
static void reloadOfReference(int &arg) //如下调用传入实参如果为10，语义是int& arg = 10,是不通过的，由于引用必须是一个合法的内存空间，即堆区或者栈区数据
{
    cout << "called void reloadOfReference(int& arg)" << endl;
    return;
}
static void reloadOfReference(const int &arg) //如下调用传入实参如果为10，语义是const int& arg = 10，该表达式为常量引用，编译器会创建临时栈区空间
{
    cout << "called void reloadOfReference(const int& arg)" << endl;
    return;
}

/**
 * @description: 这里的重载是可以和上面两个重载同时存在的(符合入参的类型不同)，但是需要注意避免调用时存在的二义性
 * 情况1：调用如果为reloadOfRefrence(a);则(int& arg)和(int arg)同时都能编译，造成二义性
 * 情况2：调用如果为reloadOfRefrence(10);则(const int& arg)和(int arg)同时都能编译，造成二义性
 * @param :
 * @return:
 */
/* static void reloadOfReference(int arg)
{
    cout << "called void reloadOfReference(int arg)" << endl;
    return;
} */

/**
 * @description: 函数的重载遇到函数的默认参数
 * @param :
 * @return:
 */
static void displayDemo(int a, int b = 10)
{
    cout << "a = " << a << " b = " << b << endl;
    return;
}

#if (CONFLICT_ERR_DISPLAY == TRUE)
static void displayDemo(int a)
{
    cout << "a = " << a << endl;
    return;
}
#endif

static void reloadMeetDefaultArgs()
{
    // 如果出现(int a, int b = 10)和(int a)两种重载可以同时存在时，所以在调用时需要注意避免二义性
#if CONFLICT_ERR_DISPLAY
    displayDemo(10);    //这样调用会造成编译器不知道走上面两个接口中的哪个，造成二义性
#endif
    displayDemo(10, 2);
    return;
}
/**
 * @description: 函数重载的条件：
 *  1、作用域必须相同
 *  2、函数名必须相同
 *  3、形参的个数、顺序、参数类型都可作为重载的条件
 *  4、返回值是否可以作为重载的条件？不可以，因为这样会造成二义性
 *  5、对于引用的重载，形参加const和不加const也可以作为重载的条件
 * @param :
 * @return:
 */
void Test16()
{
    sameNameFunc();
    sameNameFunc(28);
    sameNameFunc("lilei"); //同一作用域下可以，例如该处调用的函数实际是void sameNameFunc(string userName);
    // sameNameFunc("lilei");   //该处假定没有userName的入参，只有personName的入参，这里调用是不成功的。如果同一作用域下没有该种函数定义的话，语法错误，因为该处的调用和上两句的重名函数未在同一个作用域
    Person user;
    user.sameNameFunc("lilei"); //只有在该作用域内调用才可以

    sameNameFunc(32, 1.80);
    sameNameFunc(1.80, 32);
    sameNameFunc(1.80, 32, "hanmeimei");
    cout << "return value: " << sameNameFunc(33.5) << endl; //此处调用的是int sameNameFunc(double age);

    reloadOfReference(10); //调用void reloadOfReference(const int &arg)，根据语境，该处传入的是一个只读保护的入参(常量输入只读保护)
    int arg = 10;
    reloadOfReference(arg); //该处调用的是void reloadOfReference(int &arg)，根据语境，该处传入的是一个普通变量int arg = 10；

    reloadMeetDefaultArgs();
    return;
}