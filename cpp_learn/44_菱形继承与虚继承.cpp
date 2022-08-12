#include "cpp_learn.h"
#include "cpp_learn_inner.h"

class Animal
{
public:
  int m_Age;
};
// 虚基类 Sheep
class Sheep : virtual public Animal
{
};
// 虚基类 Tuo
class Tuo : virtual public Animal
{
};
class SheepTuo : public Sheep, public Tuo
{
};

// 菱形继承的解决方案 利用虚继承,操作的是共享的一份数据
void Test44()
{
  SheepTuo st;
  st.Sheep::m_Age = 10;
  st.Tuo::m_Age = 20;

  // 如果不适用虚继承 SheepTuo操作同名属性时不使用作用域区分会产生二义性
  cout << st.Sheep::m_Age << endl;
  cout << st.Tuo::m_Age << endl;

  //使用虚继承，即可直接访问，不需要加作用域，因为操作的是同一份数据
  st.m_Age = 30;

  cout << st.m_Age << endl;

  return;
}