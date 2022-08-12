/*
 * @Description: 设计一个立方体类
 * @Author: stone
 * @Date: 2020-02-03 14:52:33
 * @LastEditTime : 2020-02-03 17:41:17
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class cube {
private:
    int m_L;
    int m_W;
    int m_H;

public:
    void setLong(int len)
    {
        m_L = len;
        return;
    }
    void setWide(int wide)
    {
        m_W = wide;
        return;
    }
    void setHigh(int high)
    {
        m_H = high;
        return;
    }
    int getLong()
    {
        return m_L;
    }
    int getWide()
    {
        return m_W;
    }
    int getHigh()
    {
        return m_H;
    }
    int calculateS()
    {
        return 2 * m_W * m_L + 2 * m_W * m_H + 2 * m_L * m_H;
    }
    int calculateV()
    {
        return m_W * m_L * m_H;
    }
    bool cmpCubeClass(cube &c)
    {
        return m_L == c.getLong() && m_H == c.getHigh() && m_W == c.getWide();
    }
};
static bool cmpCube(cube &c1, cube &c2)
{
    if (c1.getHigh() == c2.getHigh() && c1.getWide() == c2.getWide() && c1.getLong() == c2.getLong()) {
        return true;
    }
    return false;
}
/**
 * @description:
 * @param :
 * @return:
 */

void TestEg4()
{
    cube c1;
    c1.setLong(10);
    c1.setWide(10);
    c1.setHigh(10);
    cout << "c1 S:" << c1.calculateS() << endl;
    cout << "c1 V:" << c1.calculateV() << endl;
    cube c2;
    c2.setLong(10);
    c2.setWide(10);
    c2.setHigh(12);
    if (true == cmpCube(c1, c2)) {
        cout << "cube eaqual" << endl;
        return;
    } else {
        cout << "cube not eaqual" << endl;
    }
    if (c1.cmpCubeClass(c2) == true) {
        cout << "cube equal in class" << endl;
    } else {
        cout << "cube not eaqual in class" << endl;
    }
    return;
}