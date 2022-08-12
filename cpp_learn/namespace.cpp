/*
 * @Description: namespace
 * @Author: stone
 * @Date: 2020-01-19 16:19:37
 adk @LastEditTime : 2020-01-19 16:44:46
 * @LastEditors  : stone
 */

#include "namespace.h"
#include <iostream>
using namespace std;

namespace B {
int m_A = 10;
namespace C {
    int m_A = 20;
} // namespace name

} // namespace name

void Test02()
{
    cout << "B namespace of m_A" << B::m_A << endl;
    cout << "C namespace of m_A" << B::C::m_A << endl;
}