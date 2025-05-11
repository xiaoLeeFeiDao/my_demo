#include "cpp_learn_inner.h"
#include <stdio.h>

void Test07() {
    // 直接使用其他文件中定义的const变量
    printf("[C] a = %d (证明C的const默认外部链接)\n", a);
}
