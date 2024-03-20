#pragma once

#include "../../shared/include/autopilot_command.h"
#include "../../shared/include/light_mode.h"

int getAutopilotCommand(AutopilotCommand &command);
int sendAutopilotCommand(AutopilotCommand command);

int getRsaKey(char* e, char* n);
int setServerRsaKey(char* key);
int signMessage(char* message, char* signature);
int checkSignature(char* message);

int getCoords(int32_t &latitude, int32_t &longitude, float &altitude);

int setBuzzer(uint8_t enable);
int setMotorKillSwitch(uint8_t enable);
int setCargoLock(uint8_t enable);

int sendRequest(char* query, char* response);