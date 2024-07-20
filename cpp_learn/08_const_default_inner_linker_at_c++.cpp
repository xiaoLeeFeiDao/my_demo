#include "cpp_learn_inner.h"
#include <stdio.h>

void TestLocal0801()
{
    extern const int b;
    printf("b = %d\n", b);
    // extern const int a;
    // printf("a = %d\n", a);
}

void Test08()
{
    TestLocal0801();
}