#include "demo_inner.h"
#if SUPPORT_JSON_LIB
#include <fstream>
#include <iostream>
#include <json/json.h>

// Define structures for nested data
struct CommonData {
  int start_depth;
  int start_time;
  int stop_depth;
  int stop_time;
};

struct CylinderData {
  int type;
  int percentage_O2;
  int percentage_He;
  int limit_PO2;
};

struct ScubaRecreationalData {
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
};

struct FreediveData {
  CommonData common;
  int RRT_factor;
  int alarm_depth[10];
  int alarm_time[10];
  int alarm_surface_interval[10];
};

struct GaugeData {
  CommonData common;
};
#if 0
// Function to parse JSON and populate the structure
void parseJson(const Json::Value &root,
               ScubaRecreationalData &scubaRecreational, FreediveData &freedive,
               GaugeData &gauge) {
  // Parse ScubaRecreationalData
  const Json::Value &scubaRecreationalObj =
      root["SETTING"]["scuba_recreational"];
  scubaRecreational.common.start_depth =
      scubaRecreationalObj["common"]["start_depth"].asInt();
  scubaRecreational.common.start_time =
      scubaRecreationalObj["common"]["start_time"].asInt();
  scubaRecreational.common.stop_depth =
      scubaRecreationalObj["common"]["stop_depth"].asInt();
  scubaRecreational.common.stop_time =
      scubaRecreationalObj["common"]["stop_time"].asInt();

  scubaRecreational.algorithm = scubaRecreationalObj["algorithm"].asInt();

  const Json::Value &cylinderObj = scubaRecreationalObj["cylinder"];
  scubaRecreational.cylinder.type = cylinderObj["type"].asInt();
  scubaRecreational.cylinder.percentage_O2 =
      cylinderObj["percentage_O2"].asInt();
  scubaRecreational.cylinder.percentage_He =
      cylinderObj["percentage_He"].asInt();
  scubaRecreational.cylinder.limit_PO2 = cylinderObj["limit_PO2"].asInt();

  for (int i = 0; i < 5; ++i) {
    scubaRecreational.alarm_depth[i] =
        scubaRecreationalObj["alarm_depth"][i].asInt();
    scubaRecreational.alarm_time[i] =
        scubaRecreationalObj["alarm_time"][i].asInt();
  }

  for (int i = 0; i < 2; ++i) {
    scubaRecreational.alarm_ascent[i] =
        scubaRecreationalObj["alarm_ascent"][i].asFloat();
    scubaRecreational.alarm_descent[i] =
        scubaRecreationalObj["alarm_descent"][i].asFloat();
  }

  scubaRecreational.alarm_deco_stop_too_deep_depth =
      scubaRecreationalObj["alarm_deco_stop_too_deep_depth"].asInt();
  scubaRecreational.alarm_time_to_surface_too_long =
      scubaRecreationalObj["alarm_time_to_surface_too_long"].asInt();
  scubaRecreational.deco_stop_last_stop_depth =
      scubaRecreationalObj["deco_stop_last_stop_depth"].asInt();
  scubaRecreational.safety_stop_required_depth =
      scubaRecreationalObj["safety_stop_required_depth"].asInt();
  scubaRecreational.safety_stop_depth =
      scubaRecreationalObj["safety_stop_depth"].asInt();
  scubaRecreational.conservatism =
      scubaRecreationalObj["conservatism"].asFloat();
  scubaRecreational.safety_factor =
      scubaRecreationalObj["safety_factor"].asFloat();
  scubaRecreational.gradient_factor_high =
      scubaRecreationalObj["gradient_factor_high"].asFloat();
  scubaRecreational.gradient_factor_low =
      scubaRecreationalObj["gradient_factor_low"].asFloat();

  // Parse FreediveData
  const Json::Value &freediveObj = root["SETTING"]["freedive"];
  freedive.common.start_depth = freediveObj["common"]["start_depth"].asInt();
  freedive.common.start_time = freediveObj["common"]["start_time"].asInt();
  freedive.common.stop_depth = freediveObj["common"]["stop_depth"].asInt();
  freedive.common.stop_time = freediveObj["common"]["stop_time"].asInt();

  freedive.RRT_factor = freediveObj["RRT_factor"].asInt();

  for (int i = 0; i < 10; ++i) {
    freedive.alarm_depth[i] = freediveObj["alarm_depth"][i].asInt();
    freedive.alarm_time[i] = freediveObj["alarm_time"][i].asInt();
    freedive.alarm_surface_interval[i] =
        freediveObj["alarm_surface_interval"][i].asInt();
  }

  // Parse GaugeData
  const Json::Value &gaugeObj = root["SETTING"]["gauge"];
  gauge.common.start_depth = gaugeObj["common"]["start_depth"].asInt();
  gauge.common.start_time = gaugeObj["common"]["start_time"].asInt();
  gauge.common.stop_depth = gaugeObj["common"]["stop_depth"].asInt();
  gauge.common.stop_time = gaugeObj["common"]["stop_time"].asInt();
}

void DemoTest07() {
  // 读取 JSON 文件
  std::ifstream file("test.json");
  if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    return;
  }

  // 解析 JSON 数据
  Json::Value root;
  file >> root;

  // 关闭文件
  file.close();

  // 创建结构并解析 JSON 数据
  ScubaRecreationalData scubaRecreational;
  FreediveData freedive;
  GaugeData gauge;
  parseJson(root, scubaRecreational, freedive, gauge);

  // 访问解析后的值
  std::cout << "ScubaRecreational Common Start Depth: "
            << scubaRecreational.common.start_depth << std::endl;
  std::cout << "Freedive Common Start Depth: " << freedive.common.start_depth
            << std::endl;
  std::cout << "Gauge Common Start Depth: " << gauge.common.start_depth
            << std::endl;

  // ... 访问其他解析后的值

  return;
}
#endif
#endif
