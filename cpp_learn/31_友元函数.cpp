/*
 * @Description: 友元函数
 * @Author: stone
 * @Date: 2020-02-11 17:53:41
 * @LastEditTime : 2020-02-12 11:03:16
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Building;
//类作为友元函数
class GoodFriend {
public:
    GoodFriend();
    void visit();

private:
    Building *myRoom;
};
class GoodFriend2 {
public:
    GoodFriend2();
    void visit();
    void visit2();

private:
    Building *myRoom2;
};
class Building {
public:
    // 全局友元函数
    friend void goodfriend(const Building &myRoom);
    // 类的友元
    friend class GoodFriend;
    // 友元成员函数
    friend void GoodFriend2::visit();
    Building()
    {
        this->m_Sittingroom = "客厅";
        this->m_Bedroom = "卧室";
    }
    string m_Sittingroom;

private:
    string m_Bedroom;
};

GoodFriend::GoodFriend()
{
    this->myRoom = new Building;
}
void GoodFriend::visit()
{
    cout << "好基友正在访问： " << this->myRoom->m_Sittingroom << endl;
    // 如果友元在类中声明，则可以执行下语句
    cout << "好基友正在访问： " << this->myRoom->m_Bedroom << endl;
}

GoodFriend2::GoodFriend2()
{
    this->myRoom2 = new Building;
}
void GoodFriend2::visit()
{
    cout << "好基友正在访问： " << this->myRoom2->m_Sittingroom << endl;
    cout << "好基友正在访问： " << this->myRoom2->m_Bedroom << endl;
}
void GoodFriend2::visit2()
{
    cout << "坏基友正在访问： " << this->myRoom2->m_Sittingroom << endl;
    // cout << "坏基友正在访问： " << this->myRoom2->m_Bedroom << endl;
}

//全局函数作为友元函数
void goodfriend(const Building &myRoom)
{
    cout << "访问: " << myRoom.m_Sittingroom << endl;
    //如果不是友元函数，就不能访问类内的私有属性
    // cout << "访问: " << myRoom.m_Bedroom << endl;

    //如果想要在类外也能访问私有属性，则需要在类的内部做一个友元的声明，即调用函数如果是全局函数,其内部如果需要访问
    //私有属性，需要将还调用函数的声明前面加关键字friend，并将这句声明放入类的内部只要是类内就可以，不管是public、private、protected都行
    cout << "访问: " << myRoom.m_Bedroom << endl;
}

/**
 * @description: 友元类注意：
 * 1、友元关系不能被继承
 * 2、友元关系是单向的，类A是类B的朋友，但类B不一定是类A的朋友
 * 3、友元关系不具有传递性，类B是类A的朋友，类C是类B的朋友，但不一定类C是类A的朋友
 * @param :
 * @return:
 */
void Test31()
{
    //友元函数
    // Building myRoom;
    // goodfriend(myRoom);

    // 友元类
    // GoodFriend bf;
    // bf.visit();

    // 友元成员函数
    GoodFriend2 bf2;
    bf2.visit();
    bf2.visit2();
    return;
}