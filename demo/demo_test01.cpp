/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-04-02 10:44:33
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 10:45:08
 * @FilePath: /test_win11/demo/demo_test01.cpp
 * @Description: 
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
/* TLV解析
1.题目描述
TLV 编码�?�? [ Tag Length Value ] 格式进�?�编码的,一段码流中的信元用Tag标识, Tag在码流中�?一不重�? ,Length表示信元Value的长�?,Value表示信元的�?.
码流以某信元的Tag开�?,Tag固定�? 一�?字节,Length固定占两�?字节,字节序为 小�??�? .
现给定TLV格式编码的码�?,以及需要解码的信元Tag,请输出�?�信元的Value.
输入码流�?16进制字�?�中,不包�?小写字母,且�?�求输出�?16进制字�?�串�?也不要包�?小写字母;
码流字�?�串的最大长度不超过50000�?字节.

2.输入输出描述
输入描述�?
输入的�??一行为一�?字�?�串,表示待解码信元的 Tag ;
输入的�??二�?�为一�?字�?�串,表示待解码的 16进制码流 ,字节之间用空格分�? .

输出描述:
输出一�?字�?�串,表示待解码信元以16进制表示�? Value .

3.示例
输入�?
31
32 01 00 AE 90 02 00 01 02 30 03 00 AB 32 31 31 02 00 32 33 33 01 00 CC

输出�?
32 33

4.说明
(1)需要解析的信元的Tag�?31,从码流的起�?��?�开始匹�?,
Tag�?32的信元长度为1(01 00,小�??序表示为1);
(2)�?二个信元的Tag�?90,其长度为2;
(3)�?三个信元的Tag�?30,其长度为3;
(4)�?四个信元的Tag�?31,其长度为2(02 00),所以返回长度后面的两个字节即可,�?32 33
*/
#include <cstdio>
#include "demo_inner.h"
#include <stdlib.h>
#include <cstring>
#define CODE_STREAM_LENGTH 8
int g_test = 3;

void DemoTest01()
{
    char tagBuf = 0x00;
    char tmpBuf = 0x00;
    g_test = 5;
    char *codeStream = (char*)malloc(CODE_STREAM_LENGTH);
    int i = 0;
    if (codeStream == NULL) {
        return;
    }
    memset(codeStream, 0, sizeof(char) * CODE_STREAM_LENGTH);
    /*
    char ch;
    printf("请输入字�?ch�?");// 1 2 3 回车
    scanf("%s", &ch);// 读取123
    printf("字�??ch的值：%s\n",ch);//输出 字�??ch的值：123
    char c_tmp;
    while ((c_tmp = getchar() != '\n') && c_tmp != EOF);
    */

    scanf("%c", &tagBuf);
    getchar();

    scanf("%c", &tmpBuf);
    getchar();
    while(tmpBuf != '\n') {
        codeStream[i] = tmpBuf;
        i++;
        if (i >= CODE_STREAM_LENGTH -2) {
            break;
        }
        scanf("%c", &tmpBuf);

    }
    return;
}