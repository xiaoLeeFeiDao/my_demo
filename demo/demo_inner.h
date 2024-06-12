#ifndef __DEMO_INNER_H__
#define __DEMO_INNER_H__

#ifdef __cplusplus
extern "C" {
#endif
void DemoTest01();
void DemoTest02();
void DemoTest03();
void DemoTest04();
#ifdef SUPPORT_JSON_LIB
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