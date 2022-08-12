/*
 * @Description: 打印机单例模式
 * @Author: stone
 * @Date: 2020-02-10 11:01:02
 * @LastEditTime : 2020-02-14 21:25:18
 * @LastEditors  : stone
 */
#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;
class Printer {
public:
    static Printer *getInstance()
    {
        return onePrt;
    }
    void setCount(int num)
    {
        count = num;
    }
    int getCount()
    {
        return count;
    }
    void display(string text, int num)
    {
        cout << "打印内容：" << text << endl;
        count = num;
        count++;
        cout << "打印次数：" << count << endl;
    }

private:
    static Printer *onePrt;
    int count;
    Printer()
    {
        count = 0;
        // cout << "无参构造" << endl;
    }
    Printer(const Printer &p)
    {
        cout << "拷贝构造" << endl;
    }
};
Printer *Printer::onePrt = new Printer;
/**
 * @description:
 * @param :
 * @return:
 */
void Test26()
{
    // Printer* p = Printer::getInstance();
    // p->display("请假申请", p->getCount());
    // p->display("入党申请", p->getCount());
    // p->display("入职申请", p->getCount());
    // p->display("离职申请", p->getCount());
    return;
}
