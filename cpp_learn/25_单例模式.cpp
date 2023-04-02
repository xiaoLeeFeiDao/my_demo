/*
 * @Description:单例模式
 * @Author: stone
 * @Date: 2020-02-09 12:17:56
 * @LastEditTime : 2020-02-14 21:25:02
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class ChairMan {
public:
    //     ChairMan()
    //     {
    //             cout<< "自定义public构造函数"<<endl;
    //     }
    // static ChairMan* sigleMan;
    static ChairMan *getInstance()
    {
        return sigleMan;
    }

private:
    ChairMan()
    {
        // cout << "自定义private构造函数" << endl;
    }
    ChairMan(const ChairMan &p)
    {
        cout << "自定义private拷贝构造函数" << endl;
    }
    static ChairMan *sigleMan;
};

ChairMan *ChairMan::sigleMan = new ChairMan; //唯一主席类的指针，共享数据

/**
 * @description:
 * @param :
 * @return:
 */
void Test25()
{
    //// 如果默认构造函数是public，则可以创建多个对象
    // ChairMan p1;
    // ChairMan p2;
    // ChairMan* p3 = new ChairMan;

    //// 如果想要只能创建一个对象，则需要将默认构造函数和拷贝构造函数由public改为private
    // ChairMan* c1 = ChairMan::sigleMan;
    // ChairMan* c2 = ChairMan::sigleMan;
    // if (c1 == c2) {
    //     cout << "c1 == c2" << endl;
    // } else {
    //     cout << "c1 != c2" << endl;
    // }
    // ChairMan::sigleMan = nullptr;  //如果这个sigleMan为public，那么类外可以对其进行访问修改，作为一个共享的数据，这是非常危险的操作

    //// 因此，需要将该静态成员属性设置为私有的属性，然后对外提供一个可读的接口，这样就能确保数据的安全，类外无法修改这个共享数据
    // ChairMan* c1 = ChairMan::getInstance();
    // ChairMan* c2 = ChairMan::getInstance();
    // if (c1 == c2) {
    //     cout << "c1 == c2" << endl;
    // } else {
    //     cout << "c1 != c2" << endl;
    // }

    // ChairMan* c3 = new ChairMan(*c1);   //可以看到，如果不对默认拷贝构造函数私有，则仍可以创建多个对象
    // if (c1 == c3) {
    //     cout << "c1 == c3" << endl;
    // } else {
    //     cout << "c1 != c3" << endl;
    // }
    return;
}