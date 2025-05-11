#include "cpp_learn_inner.h"
#include <stdio.h>

void Test08() {
    // 测试C++的const链接属性
    extern const int b;  // 必须这样声明
    
    // 尝试访问未加extern的const变量（将导致链接错误）
    // const int c = 30;  // 如果取消注释下面一行会链接失败
    // extern const int c;  // 错误！无法找到定义
    
    printf("[C++] b = %d (证明C++需要显式extern)\n", b);
}
