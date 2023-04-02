#include <iostream>
#include <string>
#include "cpp_learn_inner.h"
using namespace std;
template <class T>
int myAdd(T a, T b)
{
    return a + b;
}

int myAdd(int a, int b)
{
    return a + b;
}

int myAdd(int a, char c)
{
    return a + c;
}

// 函数模板可以像普通函数一样被重载
template <class T>
void print(T a)
{
    cout << "a = " << a << endl;
}

template <class T>
void print (T a, T b)
{
    cout << "hello" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "world" << endl;
}
// 返回值不是重载的条件
void Test46()
{
    int a = 10, b = 20;
    char c = 'c', d = 'd';
    // 如果同名同类型入参时，优先采用普通函数，如果编译器匹配不到普通函数的定义时，再匹配模板函数
    cout << myAdd(a, b) << endl;
    // <>表示优先采用模板函数，模板函数必须严格的类型匹配
    cout << myAdd<>(a, b) << endl;
    print(a);
    print(a, b);
    // 普通函数可进行自动类型转换
    cout << myAdd(a, c) << endl;
    cout << myAdd(c, d) << endl;
}

#ifdef CONTENT
函数模板机制结论:
编译器并不是把函数模板处理成能够处理任何类型的函数
函数模板通过具体类型产生不同的函数
编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码再次进行编译
#endif // 0