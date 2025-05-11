#ifndef __CPP_LEARN_INER_H__
#define __CPP_LEARN_INER_H__
#include "feature.h"

#ifdef __cplusplus
extern "C" {
#endif
// C风格声明（证明C的const默认外部链接）
extern const int a;  // 只需要声明，定义在.c文件中

// C++风格声明（证明C++需要显式extern）
#ifdef __cplusplus
extern const int b;  // C++中必须显式extern
#endif

#define CONFLICT_ERR_DISPALY FALSE
void Test01();
void Test02();
void Test03();
void Test04();
void Test0501();
void Test0502();
void Test06();
void Test07();
void Test08();
void Test09();
void Test10();
void Test11();
void Test12();
void Test13();
void Test14();
void Test15();
void Test16();
void Test17();
void Test18();
void Test19();
void Test20();
void Test21();
void Test22();
void Test23();
void Test24();
void Test25();
void Test26();
void Test27();
void Test28();
void Test29();
void Test30();
void Test31();
void Test32();
void Test33();
void Test34();
void Test35();
void Test36();
void Test37();
void Test38();
void Test39();
void Test40();
void Test41();
void Test42();
void Test43();
void Test44();
void Test45();
void Test46();
void Test47();
void Test48();
void Test49();
void Test50();
void Test51();
void Test52();
void TestEg1();
void TestEg2();
void TestEg3();
void TestEg4();
void TestEg5();
void TestEg6();
void TestEg7();
#ifdef __cplusplus
}
#endif

#endif
