/*
 * @Description: 指针运算符重载
 * @Author: stone
 * @Date: 2020-02-14 13:43:59
 * @LastEditTime : 2020-02-14 22:08:00
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class PrtType {
public:
    PrtType()
    {
        cout << "PrtType默认构造" << endl;
        this->m_Age = 0;
    }
    PrtType(int age)
    {
        cout << "PrtType有参构造" << endl;
        this->m_Age = age;
    }
    void showInfo()
    {
        cout << "m_Age = " << m_Age << endl;
        return;
    }
    ~PrtType()
    {
        cout << "PrtType析构" << endl;
    }

private:
    int m_Age;
};

class SmartPtr {
public:
    SmartPtr()
    {
        this->m_User = NULL;
    }
    SmartPtr(PrtType *User)
    {
        cout << "SmartPtr有参构造" << endl;
        this->m_User = User;
    }
    SmartPtr(const SmartPtr &User)
    {
        this->m_User = User.m_User;
    }
    PrtType *operator->()
    {
        return this->m_User;
    }
    PrtType &operator*()
    {
        return *(this->m_User);
    }
    void showInfo()
    {
        cout << "m_User = " << this->m_User << endl;
        return;
    }
    ~SmartPtr()
    {
        if (this->m_User != NULL) {
            cout << "SmartPtr析构" << endl;
            delete this->m_User;
            this->m_User = NULL;
        }
    }

private:
    PrtType *m_User;
};

/**
 * @description:
 * @param :
 * @return:
 */
void Test34()
{
    // PrtType* p = new PrtType(18);
    // delete p构造;

    //创建智能指针，可以使new对象PrtType在SmartPtr实例化的sp对象的析构中delete这个new出来的指针
    //显示法实例化有参构造`
    SmartPtr sp = SmartPtr(new PrtType); // new + 类名返回一个该类的指针，new会这个对象调用默认构造
    //这个new出来的指针刚好作为SmartPtr的有参构造的实参,然后调用SmartPtr的有参构造函数
    //但是sp是一个对象，并不是我们想要的指针(下语句为未定义->运算符重载`)
    // sp->showInfo();  //编译不通过

    //如何才能实现上语句，需要利用指针运算符重载，让其使用sp->m_Age能够类似于Test34中的第一句p指针的作用,即p->m_Age?
    sp->showInfo(); //本来应该是sp->->showInfo(),即sp->重载返回的是一个PrtType的指针,然后才->showInfo(),这里只能这种格式
    // 是因为编译器做了优化,不允许使用sp->->showInfo(),由于这种格式太诡异,所以编译器简化为sp->showInfo()
    // sp->->showInfo();    // 这样编译不通过

    //指针可以解引用,但是我们的sp是不可以解引用的(下语句没有才SmartPtr中对*进行运算符重载)
    // (*sp).showInfo();   //这样当前不使用*运算符的重载,编译不通过
    // 需要对*进行运算符重载,使用PrtType& operator*()来重载
    (*sp).showInfo();
    return;
}