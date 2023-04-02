/*
 * @Description: 继承
 * @Author: stone
 * @Date: 2020-03-05 12:12:51
 * @LastEditTime: 2022-03-13 10:27:48
 * @LastEditors: stone
 */

#include "cpp_learn_inner.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    int m_Age;
};
class Sheep : virtual public Animal {
};
class Tuo : virtual public Animal {
};
class SheepTuo : public Sheep, public Tuo {
};

class Base {
public:
    void headerInfo()
    {
        cout << "headerinfo show" << endl;
    }
    void footerInfo()
    {
        cout << "footerInfo show" << endl;
    }
    void pubLeft()
    {
        cout << "publicleftinfo show" << endl;
    }
};
class Games : public Base {
public:
    void showGameInfo()
    {
        cout << "showGameInfo" << endl;
    }
};
class News : public Base {
public:
    void showNewsInfo()
    {
        cout << "showNewInfo" << endl;
    }
};
static void howToUser()
{
    News news;
    Games games;
    news.footerInfo();
    news.headerInfo();
    news.pubLeft();
    news.showNewsInfo();
    games.footerInfo();
    games.headerInfo();
    games.pubLeft();
    games.showGameInfo();
}
/**
 * @description: 继承方式
 * @param :
 * @return:
 */
//*************公共继承****************
class Base1 {
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son1 : public Base1 {
public:
    void func()
    {
        m_A = 100; // m_A在Son1中是public权限，可以在类内类外访问
        m_B = 102; // m_B在Son1中是protected权限，由于该属性为protected权限，所以只可以在类内访问
        // m_C = 132; //m_C不能在Son1中访问，因为在父类Base1中是私有权限，这里不能进行访问
    }

private:
protected:
};

//**************保护继承*********************
class Base2 {
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son2 : protected Base2 {
public:
    void func()
    {
        m_A = 102; // m_A在Son2中是可以访问的，访问权限为protected，该类内可以访问，类外不可以访问
        m_B = 123; // m_B在Son2中是可以访问的，访问权限为protected，该类内可以访问，类外不可以访问
        // m_C = 32;//m_C在Son2中是不可以访问的，属于基类私有属性
    }

protected:
private:
};
//****************私有继承***********
class Base3 {
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son3 : private Base3 {
public:
    void func()
    {
        m_A = 10054;
        m_B = 23;
        // m_C = 2345; //m_C在Son2中是不可以访问的，属于基类私有属性
    }

protected:
private:
};
static void extendStyle()
{
    Son1 son1;
    son1.m_A = 102332;
    cout << "son1.m_A:" << son1.m_A << endl;
    // son1.m_B = 2343; //这里为类外访问，该属性的权限在Son1中为protected，因此，在类外是不可以访问的，只可以在类内访问
    // son1.m_C = 2324343; //私有属性，类内类外都不能访问
    // Son2 son2;
    // cout << "son2.m_A:" << son2.m_A << endl;
    // son2.m_A = 100; //这里为类外访问，访问时会报错，由于继承时的方式为protected，Son2中的该属性由public改为proteced，只能在类内访问
    // son2.m_B = 1087788; //这里为类外访问，访问时会报错
    // son2.m_C = 2324343; //私有属性，类内类外都不能访问
    // Son3 son3;
    // cout << "son3.m_A:" << son3.m_A << endl;
    // son3.m_A = 1234; //这里为类外访问，访问时会报错，由于继承时的方式为private，Son3中的该属性由public改为private，只能类内访问
    // son3.m_B = 23245;
    // son3.m_C = 34341231;
}
/**
 * @description: 1、继承可以减少重复代码
 * 2、基类--派生类   父类--子类
 * 3、语法：class 子类名:继承方式 父类名
 * @param :
 * @return:
 */
void Test38()
{
    howToUser();
    extendStyle();
    SheepTuo st;
    st.Sheep::m_Age = 10;
    st.Tuo::m_Age = 20;
    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;
    cout << st.m_Age << endl;
    cout << sizeof(st) << endl;
    return;
}