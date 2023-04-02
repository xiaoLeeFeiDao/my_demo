/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2022-11-01 00:29:20
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 08:06:42
 * @FilePath: /test_win11/cpp_learn/03_命名空间.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "cpp_learn_inner.h"
#include "game1.h"
#include "game2.h"
#include <iostream>
using namespace std;

namespace B
{
    int m_A = 10;
    namespace C
    {
        int m_A = 20;
    } // namespace name
} // namespace name

int VeryLongName::m_G = 5;

void Test03()
{
    // 如果goAtk同时包含在game1.h和game2.h 直接调用goAtk会报错， 因为如果两个头文件中不用namespace把两个方法包起来 编译器无法区分该调用那个方法
    // 二义性
    // goAtk();
    LOL::goAtk();
    gloryKing::goAtk();
    cout << "B namespace of m_A" << B::m_A << endl;
    cout << "C namespace of m_A" << B::C::m_A << endl;
    cout << "in 03_命名空间下打印:匿名命名空间 m_C = " << m_C << endl;

    cout << "在game1.h中声明,game.cpp中定义的m_StuAge = "<< LOL::m_stuAge << endl;
    LOL::m_LOL_static_Age = 23;
    cout << "in 03_命名空间.cpp:有名的命名空间 LOL::m_LOL_static_Age = " << LOL::m_LOL_static_Age << endl;
    ::MyPrint();

    // 7、命名空间可以起别名
    namespace VeryShortName = VeryLongName;
    cout << "起别名VeryShortName ==> " << VeryShortName::m_G << endl;
    cout << "原名VeryLongName ==> " << VeryLongName::m_G << endl;
}