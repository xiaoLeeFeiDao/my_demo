#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

template <class T> class person {
public:
  person(T id, T age) {
    this->mId = id;
    this->mAge = age;
  }
  void show() { cout << "mId = " << mId << ", mAge = " << mAge << endl; }

public:
  T mId;
  T mAge;
};

void Test48() {
  // 函数模板在调用的时候，可以自动类型推导
  // 类模板必须显式指定类型
  person<int> p(10, 20);
  p.show();
}