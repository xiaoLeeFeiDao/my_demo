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