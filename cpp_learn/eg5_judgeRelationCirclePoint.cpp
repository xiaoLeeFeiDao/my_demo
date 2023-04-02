/*
 * @Description: 判断点和圆的关系
 * @Author: stone
 * @Date: 2020-02-03 17:38:51
 * @LastEditTime : 2020-02-04 09:24:38
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    int m_X;
    int m_Y;

public:
    void setX(int x)
    {
        m_X = x;
        return;
    }
    void setY(int y)
    {
        m_Y = y;
        return;
    }
    int getX()
    {
        return m_X;
    }
    int getY()
    {
        return m_Y;
    }
};
class Circle {
private:
    Point m_P;
    int m_R;

public:
    void setR(int r)
    {
        m_R = r;
        return;
    }
    int getR()
    {
        return m_R;
    }
    void setP(Point p)
    {
        m_P.setX(p.getX());
        m_P.setY(p.getY());
        return;
    }
    Point getP()
    {
        return m_P;
    }
    void IsinCircleByClass(Point &p)
    {
        int distance = ((m_P.getX() - p.getX()) * (m_P.getX() - p.getX())) + ((m_P.getY() - p.getY()) * (m_P.getY() - p.getY()));
        int rDistance = m_R * m_R;

        if (distance > rDistance) {
            cout << "p is out c in class " << endl;
            return;
        }
        cout << "p is in c in class" << endl;
        return;
    }
};
static void IsinCircle(Circle &cir, Point &poi)
{
    int distance = (cir.getP().getX() - poi.getX()) * (cir.getP().getX() - poi.getX()) + (cir.getP().getY() - poi.getY()) * (cir.getP().getY() - poi.getY());
    int rDistance = cir.getR() * cir.getR();
    if (distance > rDistance) {
        cout << "p is out c" << endl;
        return;
    }
    cout << "p is in c" << endl;
    return;
}
/**
 * @description:
 * @param :
 * @return:
 */
void TestEg5()
{
    Circle c;
    Point cP;
    cP.setX(10);
    cP.setY(10);
    c.setR(2);
    c.setP(cP);

    Point p;
    p.setX(3);
    p.setY(4);
    IsinCircle(c, p);
    c.IsinCircleByClass(p);
    return;
}
