#include "demo_inner.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALASE_NAME_LEN 16

typedef enum {
    ANDROID_HUAWEI = 1,
    ANDROID_XIAOMI = 2,
    APPLE_IPHONE13 = 3
} DevType;

typedef enum {
    YELLOW = 1,
    BLACK = 2,
    WHITE = 3,
    BLUE = 4,
    RED = 5,
    GREEN = 6
} ColorType;

typedef struct {
    DevType devType;
    char version[16];
    ColorType appearence;
    char *alas;
} Phone;

typedef struct {
    int age;
    int high;
    int id;
    char *name;
    Phone *phoneList;
    int phoneListNum;
} Person;

static void ReleaseAllMalloc(Person objFree)
{
    for(int i = 0; i < objFree.phoneListNum; i++) {
        if(objFree.phoneList != NULL) {
            if (objFree.phoneList[i].alas != NULL) {
                free(objFree.phoneList[i].alas);
                objFree.phoneList[i].alas = NULL;
            }
            free(objFree.phoneList);
            objFree.phoneList = NULL;
        }
    }
}

void DemoTest02()
{
    Person stone;
    memset(&stone, 0, sizeof(Person));

    stone.phoneListNum = 3;
    stone.phoneList = (Phone*)malloc(stone.phoneListNum);
    if (stone.phoneList == NULL) {
        return;
    }

    stone.phoneList[0].alas = (char*)malloc(ALASE_NAME_LEN);
    if (stone.phoneList[0].alas == NULL) {
        return;
    }
    strcpy(stone.phoneList->alas, "iphone13");

    ReleaseAllMalloc(stone);

    return;
}