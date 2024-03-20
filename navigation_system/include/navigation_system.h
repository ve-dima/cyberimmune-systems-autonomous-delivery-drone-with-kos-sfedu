#pragma once

#include <stdint.h>

int initNavigationSystem();
int initSensors();

void getSensors();
int getCoords(int32_t &latitude, int32_t &longitude, float &altitude);