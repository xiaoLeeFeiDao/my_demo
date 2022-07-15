#include "cpp_learn.h"

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

// 菱形继承造成资源浪费 利用虚继承解决
void test44()
{
  SheepTuo st;
  st.Sheep::m_Age = 10;
  st.Tuo::m_Age = 20;

  // SheepTuo继承的基类如果不是虚函数，访问m_Age时需要加作用域，不然会有二义性
  cout << st.Sheep::m_Age << endl;
  cout << st.Tuo::m_Age << endl;

  // 使用虚继承后，实例化的对象st的成员属性m_Age资源就只有一份了
  st.m_Age = 30;
  cout << st.m_Age << endl;

  return;
}