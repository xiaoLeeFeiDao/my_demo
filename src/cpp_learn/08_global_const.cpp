// 08_global_const.cpp
// const int b = 20; // 在cpp文件中，这个变量的作用域如果有const修饰，它的作用域就在这个文件
// 如果这个文件是c文件，编译可以通过，如果是cpp文件，就会编译报错
// 那如果是cpp该如何解决呢？
// 需在const前面加extern修饰
#include "cpp_learn_inner.h"

// C++中必须显式extern才能外部链接
extern const int b = 20;  // 显式外部链接
