#include "demo_inner.h"
#if SUPPORT_OPENSSL_LIB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/evp.h>

#define MAX_FILENAME_LENGTH 64
#define DIVING_PILING_FILENAME_CONF "diving_piling_config.mp3"
#define DIVING_PILING_FILENAME_FREEDIVE "freedive.mp3"
#define DIVING_PILING_FILENAME_GAUGE "gauge.mp3"
#define DIVING_PILING_FILENAME_SCUBA "scuba.mp3"
#define DIVING_PILING_FILENAME_SCUBA_ALARM_DOT "scuba_alarm_dot.mp3"
#define DIVING_PILING_FILENAME_SCUBA_ALARM_JSON "scuba_alarm_json.mp3"
#define DIVING_PILING_FILENAME_SCUBA_TTS_DOT "scuba_tts_dot.mp3"
#define DIVING_PILING_FILENAME_SCUBA_TTS_JSON "scuba_tts_json.mp3"
#define DIVING_PILING_FILEPATH "/home/stone/code/my_demo/dot/"
void calculateMD5(const char *filename, char *md5sum)
{
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    EVP_MD_CTX *mdContext;
    const EVP_MD *mdType = EVP_md5();  // 使用MD5算法

    mdContext = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdContext, mdType, NULL);

    unsigned char data[1024];
    size_t bytesRead;

    while ((bytesRead = fread(data, 1, sizeof(data), file)) != 0) {
        EVP_DigestUpdate(mdContext, data, bytesRead);
    }

    unsigned int mdLen;
    unsigned char mdValue[EVP_MAX_MD_SIZE];
    EVP_DigestFinal_ex(mdContext, mdValue, &mdLen);
    fclose(file);

    EVP_MD_CTX_free(mdContext);

    for (unsigned int i = 0; i < mdLen; i++) {
        snprintf(md5sum + 2 * i, 2, "%02x", mdValue[i]);
    }
    md5sum[MAX_FILENAME_LENGTH - 1] = '\0';
}

void copyFile(const char *source, const char *destination)
{
    FILE *sourceFile = fopen(source, "rb");
    FILE *destinationFile = fopen(destination, "wb");

    if (!sourceFile || !destinationFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char data[1024];
    size_t bytesRead;

    while ((bytesRead = fread(data, 1, sizeof(data), sourceFile)) != 0) {
        fwrite(data, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}


void DemoTest04()
{
    const char *fileNames[] = {
        DIVING_PILING_FILENAME_CONF,
        DIVING_PILING_FILENAME_FREEDIVE,
        DIVING_PILING_FILENAME_GAUGE,
        DIVING_PILING_FILENAME_SCUBA,
        DIVING_PILING_FILENAME_SCUBA_ALARM_DOT,
        DIVING_PILING_FILENAME_SCUBA_ALARM_JSON,
        DIVING_PILING_FILENAME_SCUBA_TTS_DOT,
        DIVING_PILING_FILENAME_SCUBA_TTS_JSON
    };

    for (int i = 0; i < sizeof(fileNames) / sizeof(fileNames[0]); i++) {
        char sourcePath[256];
        char destinationPath[256];
        snprintf(sourcePath, sizeof(sourcePath), "%s%s", DIVING_PILING_FILEPATH, fileNames[i]);
        char md5sum[MAX_FILENAME_LENGTH];
        calculateMD5(sourcePath, md5sum);
        snprintf(destinationPath, sizeof(destinationPath), "%s%s", DIVING_PILING_FILEPATH, md5sum);
        copyFile(sourcePath, destinationPath);
    }
}
#endif