#ifndef __DEMO_INNER_H__
#define __DEMO_INNER_H__
#include "feature.h"
#define SUPPORT_OPENSSL_LIB FALSE
#define SUPPORT_JSON_LIB FALSE
void demo_cmark01();

#ifdef __cplusplus
// 只对C接口使用extern "C"
extern "C" {
#endif

// C接口声明
void DemoTest01();
void DemoTest02();
#if (SUPPORT_OPENSSL_LIB)
void DemoTest04();
#endif

#ifdef __cplusplus
} // 结束C接口部分

// C++接口声明（不使用extern "C"）
void DemoTest03();  // C++实现
#if(SUPPORT_JSON_LIB)
void DemoTest05();
void DemoTest06();
#if !defined(__APPLE__)
void DemoTest07();
#endif
#endif

#endif // __cplusplus
#endif
