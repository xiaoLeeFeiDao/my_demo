/*
 * @Author: stone8419 XiaoLeeFeiDao@yandex.com
 * @Date: 2023-04-02 10:44:33
 * @LastEditors: stone8419 XiaoLeeFeiDao@yandex.com
 * @LastEditTime: 2023-04-02 10:47:49
 * @FilePath: /test_win11/demo/demo_test01.cpp
 * @Description: 
 * Copyright (c) 2023 by ${git_name} email: ${git_email}, All Rights Reserved.
 */
/* TLV����
1.��Ŀ����
TLV �����ǰ� [ Tag Length Value ] ��ʽ���б����,һ�������е���Ԫ��Tag��ʶ, Tag��������Ψһ���ظ� ,Length��ʾ��ԪValue�ĳ���,Value��ʾ��Ԫ��ֵ.
������ĳ��Ԫ��Tag��ͷ,Tag�̶�ռ һ���ֽ�,Length�̶�ռ�����ֽ�,�ֽ���Ϊ С���� .
�ָ���TLV��ʽ���������,�Լ���Ҫ�������ԪTag,���������Ԫ��Value.
����������16�����ַ���,������Сд��ĸ,��Ҫ�������16�����ַ�����Ҳ��Ҫ����Сд��ĸ;
�����ַ�������󳤶Ȳ�����50000���ֽ�.
2.�����������
����������
����ĵ�һ��Ϊһ���ַ���,��ʾ��������Ԫ�� Tag ;
����ĵڶ���Ϊһ���ַ���,��ʾ������� 16�������� ,�ֽ�֮���ÿո�ָ� .
�������:
���һ���ַ���,��ʾ��������Ԫ��16���Ʊ�ʾ�� Value .
3.ʾ��
���룺
31
32 01 00 AE 90 02 00 01 02 30 03 00 AB 32 31 31 02 00 32 33 33 01 00 CC
�����
32 33
4.˵��
(1)��Ҫ��������Ԫ��Tag��31,����������ʼ����ʼƥ��,
TagΪ32����Ԫ����Ϊ1(01 00,С�����ʾΪ1);
(2)�ڶ�����Ԫ��Tag��90,�䳤��Ϊ2;
(3)��������Ԫ��Tag��30,�䳤��Ϊ3;
(4)���ĸ���Ԫ��Tag��31,�䳤��Ϊ2(02 00),���Է��س��Ⱥ���������ֽڼ���,��32 33
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
    printf("�������ַ�ch��");// 1 2 3 �س�
    scanf("%s", &ch);// ��ȡ123
    printf("�ַ�ch��ֵ��%s\n",ch);//��� �ַ�ch��ֵ��123
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