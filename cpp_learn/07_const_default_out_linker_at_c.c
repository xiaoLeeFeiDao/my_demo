#include "cpp_learn_inner.h"
#include <stdio.h>

void TestLocal0701()
{
    extern const int a;
    printf("a = %d\n", a);
}

void Test07()
{
    TestLocal0701();
}