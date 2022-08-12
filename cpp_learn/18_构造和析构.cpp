/*
 * @Description: 构造和析构
 * @Author: stone
 * @Date: 2020-02-04 11:16:45
 * @LastEditTime : 2020-02-15 18:53:46
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class myClass {
public:
    myClass()
    {
        cout << "无参构造函数" << endl;
    }
    myClass(int a)
    {
        m_a = a;
        cout << "有参构造函数(int a)" << endl;
    }
    myClass(const myClass &c)
    {
        m_a = c.m_a;
        cout << "拷贝构造函数" << endl;
    }
    ~myClass()
    {
        cout << "析构函数" << endl;
    }
    int getMa()
    {
        return m_a;
    }

private:
    int m_a;
};
static void Testdefine()
{
    cout << "Testdefine" << endl;
    return;
}
/**
 * @description: 构造和析构时编译器强制的，不管是否用户自定义，编译器都会构造、析构，都是在public下的，
 * 自定义时不能放入private(单例模式除外),由编译器自动调用
 * 不需要手动调用，而且编译器只会调用一次。构造和析构的函数名和类名相同
 * 构造函数：可以有参数，可以发生重载
 * 析构函数：不可以有参数，不能发生重载
 * 编译器自动调用，不需要手动调用，编译器只会调用一次
 * ---------构造函数和析构函数的调用时机------------
 * 1、使用已创建好的对象初始化另一个对象
 * 2、
 * @param :
 * @return:
 */
static void doWork(myClass c)
{
    Testdefine();
    return;
}
static myClass doWork2() //这里不能返回局部变量的引用，不然返回值的任何操作都是非法的
{
    myClass c;
    cout << "doWork2 done" << endl;
    return c;
}
void Test18()
{
    //系统默认给一个类至少提供三个函数，默认构造、拷贝构造、析构、operator=(值拷贝)
    // myClass c0; //无参构造，也叫默认构造。系统会自带默认构造，但里面没东西
    //第一种：括号法 有参构造的调用方式，拷贝构造函数的调用
    // myClass c1(10);  //有参构造括号法调用
    // myClass cl1(c1); //拷贝构造括号法调用

    //注意：无参构造不可以使用括号法调用
    // myClass c0(); //不可以这样调用无参构造函数，因为编译器会认为这是一个函数的声明
    // void Testdefine();   //函数声明可以放入一个函数的定义中

    //第二种：显示法
    // myClass c2 = myClass(10);    //有参构造显示调用
    // myClass cl2 = myClass(c2);    //拷贝构造显示调用

    //第三种：匿名法
    // myClass(10); //特点是当前语句执行完后，系统就回收了
    // cout << "aaa" << endl; //验证上语句

    //注意：拷贝构造不能使用匿名构造
    // myClass sc3(10);
    // myClass c3 = myClass(10); //实例化一个对象，用于下方拷贝函数调用使用，证明拷贝函数不能使用匿名构造
    // myClass(sc3); //不可以使用匿名构造来初始化匿名对象，系统会默认将其优化为myClass sc3;认为是重复定义
    // myClass(c3); //不可以使用匿名构造来初始化匿名对象，系统会默认将其优化为myClass c3;认为是重复定义

    //第四种：隐式法
    // myClass c4 = 10; //等价于显示法的myCLass c4 = myClass(10);一般不推荐这样的写法
    // myClass cl4 = c4; //等价于显示法的myCLass cl4 = myClass(c4);一般不推荐这样的写法

    // 调用时机第一种：值传递：c5被传递到doWork以后，类似于隐式法myClass c = c5;调用了隐式构造函数
    // myClass c5;
    // myClass c6(c5);
    // cout << c6.getMa() << endl; //由于实例化c5的时候，并未对c5的成员初始化

    // myClass c51(10);
    // myClass c61(c51);
    // cout << c61.getMa() << endl; //由于实例化方式为有参构造并对成员初始化赋值了，所以调用拷贝构造对c61该对象拷贝赋值了

    //调用时机第二种：以值传递的方式给函数的参数传值
     myClass c7;
     doWork(c7);
     cout << c7.getMa() << endl;

    // myClass c7(12);
    // doWork(c7); //由于实例化时有对成员初始化
    // cout << c7.getMa() << endl;

    // 调用时机第三种：以值的方式返回局部对象：这里的release版本是系统进行了优化，为了节省开销只做了在doWork中调用了构造函数，实际上即debug版本,
    // 该函数执行完成前，会将该函数内部要返回的对象构造了一份临时的对象，并将其返回赋给c8，当c8的作用域结束时，
    // doWork中申请的临时对象(栈空间先进先出)才会被释放，也就是c8接管了doWork的返回地址。
    // myClass c8 = doWork2();
    // 如果doWork的返回值没有被接收，则doWork执行完后就释放了返回的对象

    doWork2();
    cout << "doWork2 called done" << endl;
    return;
}
