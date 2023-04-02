//
// Created by 李磊 on 2023/3/5.
//
#include "cpp_learn_inner.h"
#include <iostream>
using namespace std;

namespace KingGlory{
    int sunwukongId = 1;
}
static void LocalTest01()
{
    int sunwukongId = 4;
    // 1、using声明
    // 当就近原则和using声明同时出现时，需要避免二义性，即使加上作用域也不起作用
//    using KingGlory::sunwukongId; // 如果在此声明，编译器报错
    // 此时使用using编译指令，编译通过；当就近原则和using编译指令混合使用时，编译器优先采用就近原则
    using namespace KingGlory;

    cout << "sunwukongId = " << sunwukongId << endl;
}
void Test04()
{
    LocalTest01();
}