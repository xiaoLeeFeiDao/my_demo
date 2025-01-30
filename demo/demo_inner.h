#ifndef __DEMO_INNER_H__
#define __DEMO_INNER_H__
#include "feature.h"
#define SUPPORT_OPENSSL_LIB FALSE
#define SUPPORT_JSON_LIB FALSE
#ifdef __cplusplus
extern "C" {
#endif
void DemoTest01();
void DemoTest02();
void DemoTest03();
#if (SUPPORT_OPENSSL_LIB)
void DemoTest04();
#endif
#if(SUPPORT_JSON_LIB)
void DemoTest05();
void DemoTest06();
#if !defined(__APPLE__)
void DemoTest07();
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif