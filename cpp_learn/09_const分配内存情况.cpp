#include <iostream>
#include <string>
#include "cpp_learn_inner.h"
using namespace std;

namespace MySpace
{
    // #define num 1024
} // namespace MySpace

    #define num 1024
void Test09()
{
    // 1、对const修饰的变量取地址时会分配临时内存，这时是修改不了const修饰的变量
    const int m_A = 10; // 放在符号表中
    int *p1 = (int*)&m_A; // 此时会分配内存
    cout << "bf chg:" << "*p1 = " << *p1 << ", p1 = " << p1 << ", &m_A = " << &m_A << ", m_A = " << m_A << endl;
    *p1 = 100; // 此时修改m_A的值是不成功的，局部常量被常量初始化时： const int m_A = 10; tmp = m_A; p = &tmp;
    cout << "aft chg:" << "*p1 = " << *p1 << ", p1 = " << p1 << ", &m_A = " << &m_A << ", m_A = " << m_A << endl;
    // 2、 const前加入extern关键字后，也会分配内存

    // 3、 使用变量来初始化const修饰的变量,这时实际可以修改成功const修饰的变量
    int b = 10;
    const int m_B = b;
    cout << "m_B = " << m_B << endl;
    // 3.1、如果m_B被分配了内存，那么就可以获取地址来对其进行修改
    int *p2 = (int*)&m_B;
    cout << "bf chg:" << "*p2 = " << *p2 << ", p2 = " << p2 << ", &m_B = " << &m_B << ", m_B = " << m_B << endl;
    *p2 = 20;
    cout << "aft chg:" << "*p2 = " << *p2 << ", p2 = " << p2 << ", &m_B = " << &m_B << ", m_B = " << m_B << endl;

    // 4、 对于自定义数据类型，也会分配内存，初始化该结构体变量为常量，但可以通过内存操控来修改该结构体变量中的成员属性
    struct Person {
        string name;
        int age;
    };
    const Person p { "Xiaol", 28 };
    // 不可以直接修改
    // p.age = 100;
    // p.name = "stone";
    Person *pp = (Person*)&p;
    pp->age = 200;
    pp->name = "lldao";
    cout << "姓名：" << pp->name << ", 年龄：" << pp->age << endl;
    // 5.尽量使用const来代替#define
    // 5.1、宏是全局的，不重视作用域
    // 5.2、const有类型，会有类型检测
    // 5.3、宏可以通过#undef卸载
    // 5.4、宏常量可以有命名空间吗？
    // using namespace MySpace;

    // cout << MySpace::num << endl;
    cout << num << endl;
    // int num = 100; // 命名冲突
}