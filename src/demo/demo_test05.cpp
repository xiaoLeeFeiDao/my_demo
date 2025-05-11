#include "demo_inner.h"
#if SUPPORT_JSON_LIB
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <cjson/cJSON.h>
// 定义结构体来承载 JSON 数据
typedef struct {
    char FILE_NAME[256];
    char TEST_CONTENT[1][256];  // 使用二维数组来模拟数组
    struct {
        int version;
        int setting_length;
        int auto_mode;
        int select_mode;
        int water_type;
        int salinity;
        int sampling_rate;
        struct {
            int age;
            int weight;
        } user;
        struct {
            struct {
                int start_depth;
                int start_time;
                int stop_depth;
                int stop_time;
            } common;
            int algorithm;
            struct {
                int type;
                int percentage_O2;
                int percentage_He;
                int limit_PO2;
            } cylinder;
            int alarm_depth[5];
            int alarm_time[5];
            double alarm_ascent[2];
            double alarm_descent[2];
            int alarm_deco_stop_too_deep_depth;
            int alarm_time_to_surface_too_long;
            int deco_stop_last_stop_depth;
            int safety_stop_required_depth;
            int safety_stop_depth;
            double conservatism;
            double safety_factor;
            double gradient_factor_high;
            double gradient_factor_low;
        } scuba_recreational;
        // 继续添加其他结构体字段...
        int checksum;
    } SETTING;
} ScubaData;

// 递归解析 JSON 对象
void parseJSON(cJSON *json, ScubaData *scubaData, const char *parent_name) {
    if (json == NULL) return;
    cJSON *current = json->child;
    while (current != NULL) {
        char full_name[256];
        if (parent_name[0] != '\0') {
            snprintf(full_name, sizeof(full_name), "%s.%s", parent_name, current->string);
        } else {
            snprintf(full_name, sizeof(full_name), "%s", current->string);
        }

        cJSON *objectItem = cJSON_GetObjectItemCaseSensitive(json, current->string);

        if (objectItem->type == cJSON_Object) {
            // 递归解析对象
            parseJSON(objectItem, scubaData, full_name);
        } else {
            // 处理基本类型
            if (objectItem->type == cJSON_Number) {
                // 处理数字
                if (strstr(full_name, "double") != NULL) {
                    // 处理 double 类型
                    double *ptr = (double *)((char *)scubaData + (size_t)&(((ScubaData *)0)->SETTING.version));
                    *ptr = current->valuedouble;
                } else {
                    // 处理 int 类型
                    int *ptr = (int *)((char *)scubaData + (size_t)&(((ScubaData *)0)->SETTING.version));
                    *ptr = current->valueint;
                }
            } else if (objectItem->type == cJSON_String) {
                // 处理字符串
                strncpy((char *)scubaData + (size_t)&(((ScubaData *)0)->FILE_NAME), objectItem->valuestring, strlen(objectItem->valuestring) + 1);
            }

            // 打印字段名和值
            printf("%s: ", full_name);
            if (objectItem->type == cJSON_String) {
                printf("\"%s\"\n", objectItem->valuestring);
            } else if (objectItem->type == cJSON_Number) {
                if (strstr(full_name, "double") != NULL) {
                    printf("%lf\n", objectItem->valuedouble);
                } else {
                    printf("%d\n", objectItem->valueint);
                }
            }
        }

        current = current->next;
    }
}

// 解析 CSV 文件
void parseCSV(char *csv_data) {

    // 在这里添加解析 CSV 的逻辑
    char *line = strtok(csv_data, "\n");
    while (line != NULL) {
        // Split the CSV line into tokens using ',' as delimiter
        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("Value: %s\n", token);
            token = strtok(NULL, ",");
        }

        line = strtok(NULL, "\n");
    }
}

// 判断文件是否为 JSON 格式
bool isJSONFile(const char *file_data, cJSON** json) {
    *json = cJSON_Parse(file_data);
    if(json) return true;
    return false;
}

bool isCSVFile( char *file_data) {
    char *line = strtok(file_data, "\n");
    // Check if the first line contains the expected column headers
    if (strcmp(line, "UTC,Pressure (mBar),Temperature (C),Time Interval") != 0) {
        printf("Unsupported CSV format: %s\n", line);
        return false;
    }

    return true;
}

void DemoTest05()
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/home/stone/code/my_demo/dot")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                char filepath[512];
                snprintf(filepath, sizeof(filepath), "/home/stone/code/my_demo/dot/%s", ent->d_name);

                FILE *file = fopen(filepath, "r");
                if (!file) {
                    printf("Error opening JSON file: %s\n", filepath);
                    continue;
                }

                fseek(file, 0, SEEK_END);
                long fileSize = ftell(file);
                fseek(file, 0, SEEK_SET);

                char *file_data = (char *)malloc(fileSize + 1);
                fread(file_data, sizeof(char), fileSize, file);
                fclose(file);
                cJSON* json;
                if (isJSONFile(file_data, &json)) {
                    ScubaData scubaData;
                    memset(&scubaData, 0, sizeof(scubaData));
                    parseJSON(json, &scubaData, "");

                    printf("Structure data:\n");
                    printf("FILE_NAME: %s\n", scubaData.FILE_NAME);
                    printf("TEST_CONTENT: %s\n", scubaData.TEST_CONTENT[0]);
                    printf("version: %d\n", scubaData.SETTING.version);

                    cJSON_Delete(json);
                    free(file_data);
                } else if (isCSVFile(file_data)) {
                    parseCSV(file_data);
                    free(file_data);
                } else {
                    printf("Unsupported file: %s\n", filepath);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Unable to open directory");
    }
}
#endif
