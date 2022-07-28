#include "cpp_learn_iner.h"
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

void test45()
{
    SheepTuo st;
    st.m_Age = 100;
    cout << sizeof(st) << endl;
    // 找到Sheep的偏移量操作
    cout << *(int *)((int *)*(int *)&st + 1) << endl;
    cout << *(uintptr_t *)((uintptr_t *)*(uintptr_t *)&st + 1) << endl;
    return;
}