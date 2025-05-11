#include "demo_inner.h"
#if SUPPORT_JSON_LIB
#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for nested data
typedef struct {
  int start_depth;
  int start_time;
  int stop_depth;
  int stop_time;
} CommonData;

typedef struct {
  int type;
  int percentage_O2;
  int percentage_He;
  int limit_PO2;
} CylinderData;

typedef struct {
  CommonData common;
  int algorithm;
  CylinderData cylinder;
  int alarm_depth[5];
  int alarm_time[5];
  float alarm_ascent[2];
  float alarm_descent[2];
  int alarm_deco_stop_too_deep_depth;
  int alarm_time_to_surface_too_long;
  int deco_stop_last_stop_depth;
  int safety_stop_required_depth;
  int safety_stop_depth;
  float conservatism;
  float safety_factor;
  float gradient_factor_high;
  float gradient_factor_low;
} ScubaRecreationalData;

typedef struct {
  CommonData common;
  int algorithm;
  CylinderData cylinder;
  int alarm_depth[5];
  int alarm_time[5];
  float alarm_ascent[2];
  float alarm_descent[2];
  float safety_factor;
  float gradient_factor_high;
  float gradient_factor_low;
} ScubaTechnicalData;

typedef struct {
  CommonData common;
  int algorithm;
  CylinderData cylinder;
  int alarm_depth[5];
  int alarm_time[5];
  float alarm_ascent[2];
  float alarm_descent[2];
} ScubaCommercialData;

typedef struct {
  CommonData common;
  int algorithm;
  CylinderData cylinder;
  int alarm_depth[5];
  int alarm_time[5];
  float alarm_ascent[2];
  float alarm_descent[2];
} ScubaCCRData;

typedef struct {
  CommonData common;
} GaugeData;

typedef struct {
  CommonData common;
  float RRT_factor;
  int alarm_depth[10];
  int alarm_time[10];
  int alarm_surface_interval[10];
} FreediveData;

typedef struct {
  CommonData common;
  float RRT_factor;
  int alarm_depth[10];
  int alarm_time[10];
  int alarm_surface_interval[10];
} HuntingData;

typedef struct {
  CommonData common;
} PoolData;

typedef struct {
  char FILE_NAME[50];
  char TEST_CONTENT[1][50];
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
  ScubaRecreationalData scuba_recreational;
  ScubaTechnicalData scuba_technical;
  ScubaCommercialData scuba_commercial;
  ScubaCCRData scuba_ccr;
  GaugeData gauge;
  FreediveData freedive;
  HuntingData hunting;
  PoolData pool;
  int checksum;
} SettingData;

void parseCommonData(cJSON *commonObj, CommonData *common) {
  common->start_depth = cJSON_GetObjectItem(commonObj, "start_depth")->valueint;
  common->start_time = cJSON_GetObjectItem(commonObj, "start_time")->valueint;
  common->stop_depth = cJSON_GetObjectItem(commonObj, "stop_depth")->valueint;
  common->stop_time = cJSON_GetObjectItem(commonObj, "stop_time")->valueint;
}
void parseFreediveData(cJSON *freediveObj, FreediveData *freedive) {
  parseCommonData(cJSON_GetObjectItem(freediveObj, "common"),
                  &freedive->common);
  freedive->RRT_factor =
      cJSON_GetObjectItem(freediveObj, "RRT_factor")->valuedouble;

  cJSON *alarm_depth_array = cJSON_GetObjectItem(freediveObj, "alarm_depth");
  cJSON *alarm_time_array = cJSON_GetObjectItem(freediveObj, "alarm_time");
  cJSON *alarm_surface_interval_array =
      cJSON_GetObjectItem(freediveObj, "alarm_surface_interval");

  for (int i = 0; i < 10; ++i) {
    freedive->alarm_depth[i] =
        cJSON_GetArrayItem(alarm_depth_array, i)->valueint;
    freedive->alarm_time[i] = cJSON_GetArrayItem(alarm_time_array, i)->valueint;
    freedive->alarm_surface_interval[i] =
        cJSON_GetArrayItem(alarm_surface_interval_array, i)->valueint;
  }
}

void parseGaugeData(cJSON *gaugeObj, GaugeData *gauge) {
  parseCommonData(cJSON_GetObjectItem(gaugeObj, "common"), &gauge->common);
}

void parseCylinderData(cJSON *cylinderObj, CylinderData *cylinder) {
  cylinder->type = cJSON_GetObjectItem(cylinderObj, "type")->valueint;
  cylinder->percentage_O2 =
      cJSON_GetObjectItem(cylinderObj, "percentage_O2")->valueint;
  cylinder->percentage_He =
      cJSON_GetObjectItem(cylinderObj, "percentage_He")->valueint;
  cylinder->limit_PO2 = cJSON_GetObjectItem(cylinderObj, "limit_PO2")->valueint;
}
void parseScubaRecreationalData(cJSON *scubaRecreationalObj,
                                ScubaRecreationalData *scubaRecreational) {
  cJSON *commonObj = cJSON_GetObjectItem(scubaRecreationalObj, "common");
  parseCommonData(commonObj, &scubaRecreational->common);

  scubaRecreational->algorithm =
      cJSON_GetObjectItem(scubaRecreationalObj, "algorithm")->valueint;

  cJSON *cylinderObj = cJSON_GetObjectItem(scubaRecreationalObj, "cylinder");
  parseCylinderData(cylinderObj, &scubaRecreational->cylinder);

  cJSON *alarm_depth_array =
      cJSON_GetObjectItem(scubaRecreationalObj, "alarm_depth");
  cJSON *alarm_time_array =
      cJSON_GetObjectItem(scubaRecreationalObj, "alarm_time");
  cJSON *alarm_ascent_array =
      cJSON_GetObjectItem(scubaRecreationalObj, "alarm_ascent");
  cJSON *alarm_descent_array =
      cJSON_GetObjectItem(scubaRecreationalObj, "alarm_descent");

  for (int i = 0; i < 5; ++i) {
    scubaRecreational->alarm_depth[i] =
        cJSON_GetArrayItem(alarm_depth_array, i)->valueint;
    scubaRecreational->alarm_time[i] =
        cJSON_GetArrayItem(alarm_time_array, i)->valueint;
  }
  for (int i = 0; i < 2; ++i) {
    scubaRecreational->alarm_ascent[i] =
        cJSON_GetArrayItem(alarm_ascent_array, i)->valuedouble;
    scubaRecreational->alarm_descent[i] =
        cJSON_GetArrayItem(alarm_descent_array, i)->valuedouble;
  }

  scubaRecreational->alarm_deco_stop_too_deep_depth =
      cJSON_GetObjectItem(scubaRecreationalObj,
                          "alarm_deco_stop_too_deep_depth")
          ->valueint;
  scubaRecreational->alarm_time_to_surface_too_long =
      cJSON_GetObjectItem(scubaRecreationalObj,
                          "alarm_time_to_surface_too_long")
          ->valueint;
  scubaRecreational->deco_stop_last_stop_depth =
      cJSON_GetObjectItem(scubaRecreationalObj, "deco_stop_last_stop_depth")
          ->valueint;
  scubaRecreational->safety_stop_required_depth =
      cJSON_GetObjectItem(scubaRecreationalObj, "safety_stop_required_depth")
          ->valueint;
  scubaRecreational->safety_stop_depth =
      cJSON_GetObjectItem(scubaRecreationalObj, "safety_stop_depth")->valueint;
  scubaRecreational->conservatism =
      cJSON_GetObjectItem(scubaRecreationalObj, "conservatism")->valuedouble;
  scubaRecreational->safety_factor =
      cJSON_GetObjectItem(scubaRecreationalObj, "safety_factor")->valuedouble;
  scubaRecreational->gradient_factor_high =
      cJSON_GetObjectItem(scubaRecreationalObj, "gradient_factor_high")
          ->valuedouble;
  scubaRecreational->gradient_factor_low =
      cJSON_GetObjectItem(scubaRecreationalObj, "gradient_factor_low")
          ->valuedouble;
}

void parse_json(const char *json_str, SettingData *settings) {
  cJSON *root = cJSON_Parse(json_str);

  if (!root) {
    const char *error_ptr = cJSON_GetErrorPtr();
    if (error_ptr != NULL) {
      fprintf(stderr, "Error before: %s\n", error_ptr);
    }
    return;
  }

  strncpy(settings->FILE_NAME,
          cJSON_GetObjectItem(root, "FILE_NAME")->valuestring,
          sizeof(settings->FILE_NAME));
  strncpy(settings->TEST_CONTENT[0],
          cJSON_GetArrayItem(cJSON_GetObjectItem(root, "TEST_CONTENT"), 0)
              ->valuestring,
          sizeof(settings->TEST_CONTENT[0]));

  cJSON *settingObj = cJSON_GetObjectItem(root, "SETTING");
  settings->version = cJSON_GetObjectItem(settingObj, "version")->valueint;
  settings->setting_length =
      cJSON_GetObjectItem(settingObj, "setting_length")->valueint;
  settings->auto_mode = cJSON_GetObjectItem(settingObj, "auto_mode")->valueint;
  settings->select_mode =
      cJSON_GetObjectItem(settingObj, "select_mode")->valueint;
  settings->water_type =
      cJSON_GetObjectItem(settingObj, "water_type")->valueint;
  settings->salinity = cJSON_GetObjectItem(settingObj, "salinity")->valueint;
  settings->sampling_rate =
      cJSON_GetObjectItem(settingObj, "sampling_rate")->valueint;

  cJSON *userObj = cJSON_GetObjectItem(settingObj, "user");
  settings->user.age = cJSON_GetObjectItem(userObj, "age")->valueint;
  settings->user.weight = cJSON_GetObjectItem(userObj, "weight")->valueint;

  parseScubaRecreationalData(
      cJSON_GetObjectItem(settingObj, "scuba_recreational"),
      &settings->scuba_recreational);
  parseFreediveData(cJSON_GetObjectItem(settingObj, "freedive"),
                    &settings->freedive);
  parseGaugeData(cJSON_GetObjectItem(settingObj, "gauge"), &settings->gauge);

  cJSON_Delete(root);
}

char *read_json_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = (char *)malloc(length + 1);
  if (!buffer) {
    fclose(file);
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  fread(buffer, 1, length, file);
  fclose(file);

  buffer[length] = '\0'; // Null-terminate the string
  return buffer;
}

void DemoTest06() {
  const char *filename = "test.json"; // Replace with the actual file name
  char *json_str = read_json_file(filename);
  SettingData settings;
  parse_json(json_str, &settings);

  printf("Common Start Depth: %d\n",
         settings.scuba_recreational.common.start_depth);
  printf("Algorithm: %d\n", settings.scuba_recreational.algorithm);
  printf("Cylinder Type: %d\n", settings.scuba_recreational.cylinder.type);

  printf("Alarm Depth: ");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", settings.scuba_recreational.alarm_depth[i]);
  }
  printf("\n");

  printf("Alarm Time: ");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", settings.scuba_recreational.alarm_time[i]);
  }
  printf("\n");

  printf("Alarm Ascent: ");
  for (int i = 0; i < 2; ++i) {
    printf("%f ", settings.scuba_recreational.alarm_ascent[i]);
  }
  printf("\n");

  printf("Alarm Descent: ");
  for (int i = 0; i < 2; ++i) {
    printf("%f ", settings.scuba_recreational.alarm_descent[i]);
  }
  printf("\n");
}
#endif
