#include "cpp_learn_inner.h"
#include <iostream>

using namespace std;
using namespace std;
class animal {
public:
    int m_Age;
};

class Sheep : virtual public animal {
};

class Tuo : virtual public animal {
};

class SheepTuo : public Sheep, public Tuo {
};
class Person {
public:
    void MyPrint()
    {
      cout << "hello" << endl;
    }
};
void Test45()
{
    SheepTuo st;

    st.m_Age = 100;
    //int *p = (int *)0x80000000;
    //cout << &p << *p << endl;
    cout << sizeof(st) << endl;
    cout << "你好 世界" << endl;
    // 找到Sheep的偏移量操作
    // cout << *(int *)((int *)*(int *)&st + 1) << endl;
    cout << *(uintptr_t*)((uintptr_t*)*(uintptr_t*)&st + 1) << endl;
    Person *p = nullptr;
    p->MyPrint();
    cout << "world" << endl;
    return;
}