/* TLV解析
1.题目描述
TLV 编码是按 [ Tag Length Value ] 格式进行编码的,一段码流中的信元用Tag标识, Tag在码流中唯一不重复 ,Length表示信元Value的长度,Value表示信元的值.
码流以某信元的Tag开头,Tag固定占 一个字节,Length固定占两个字节,字节序为 小端序 .
现给定TLV格式编码的码流,以及需要解码的信元Tag,请输出该信元的Value.
输入码流的16进制字符中,不包括小写字母,且要求输出的16进制字符串中也不要包含小写字母;
码流字符串的最大长度不超过50000个字节.

2.输入输出描述
输入描述：
输入的第一行为一个字符串,表示待解码信元的 Tag ;
输入的第二行为一个字符串,表示待解码的 16进制码流 ,字节之间用空格分隔 .

输出描述:
输出一个字符串,表示待解码信元以16进制表示的 Value .

3.示例
输入：
31
32 01 00 AE 90 02 00 01 02 30 03 00 AB 32 31 31 02 00 32 33 33 01 00 CC

输出：
32 33

4.说明
(1)需要解析的信元的Tag是31,从码流的起始处开始匹配,
Tag为32的信元长度为1(01 00,小端序表示为1);
(2)第二个信元的Tag是90,其长度为2;
(3)第三个信元的Tag是30,其长度为3;
(4)第四个信元的Tag是31,其长度为2(02 00),所以返回长度后面的两个字节即可,即32 33
*/
#include <cstdio>
#include "demo_inner.h"
#include <stdlib.h>
#include <cstring>
#define CODE_STREAM_LENGTH 8
void DemoTest01()
{
    char tagBuf = 0x00;
    char tmpBuf = 0x00;
    char *codeStream = (char*)malloc(CODE_STREAM_LENGTH);
    int i = 0;
    if (codeStream == NULL) {
        return;
    }
    memset(codeStream, 0, sizeof(char) * CODE_STREAM_LENGTH);
    /*
    char ch;
    printf("请输入字符ch：");// 1 2 3 回车
    scanf("%s", &ch);// 读取123
    printf("字符ch的值：%s\n",ch);//输出 字符ch的值：123
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