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
#define MD5_DIGEST_LENGTH 16  // MD5输出固定16字节
#define MD5_STRING_LENGTH (MD5_DIGEST_LENGTH * 2 + 1)  // 32字符+null终止符

int calculateMD5(const char *filename, char *md5sum, size_t md5sum_len) {
    // 验证输出缓冲区大小
    if (md5sum_len < MD5_STRING_LENGTH) {
        fprintf(stderr, "Output buffer too small, need at least %d bytes\n", MD5_STRING_LENGTH);
        return -1;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    EVP_MD_CTX *mdContext = EVP_MD_CTX_new();
    if (!mdContext) {
        fclose(file);
        fprintf(stderr, "Failed to create MD context\n");
        return -1;
    }

    const EVP_MD *mdType = EVP_md5();
    if (!mdType) {
        fclose(file);
        EVP_MD_CTX_free(mdContext);
        fprintf(stderr, "MD5 not available\n");
        return -1;
    }

    if (EVP_DigestInit_ex(mdContext, mdType, NULL) != 1) {
        fclose(file);
        EVP_MD_CTX_free(mdContext);
        fprintf(stderr, "Digest init failed\n");
        return -1;
    }

    unsigned char data[1024];
    size_t bytesRead;
    int success = 1;

    while ((bytesRead = fread(data, 1, sizeof(data), file)) ) {
        if (EVP_DigestUpdate(mdContext, data, bytesRead) != 1) {
            success = 0;
            break;
        }
    }

    if (ferror(file)) {
        perror("File read error");
        success = 0;
    }

    unsigned char mdValue[EVP_MAX_MD_SIZE];
    unsigned int mdLen;
    if (success && EVP_DigestFinal_ex(mdContext, mdValue, &mdLen) != 1) {
        success = 0;
    }

    fclose(file);
    EVP_MD_CTX_free(mdContext);

    if (!success) {
        fprintf(stderr, "MD5 calculation failed\n");
        return -1;
    }

    // 将二进制哈希转换为十六进制字符串
    for (unsigned int i = 0; i < mdLen; i++) {
        snprintf(md5sum + 2 * i, 3, "%02x", mdValue[i]);  // 注意缓冲区改为3
    }
    md5sum[MD5_STRING_LENGTH - 1] = '\0';  // 确保null终止

    return 0;  // 成功
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
        calculateMD5(sourcePath, md5sum, sizeof(md5sum));
        snprintf(destinationPath, sizeof(destinationPath), "%s%s", DIVING_PILING_FILEPATH, md5sum);
        copyFile(sourcePath, destinationPath);
    }
}
#endif
