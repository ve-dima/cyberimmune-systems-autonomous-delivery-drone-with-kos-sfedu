#pragma once

#include <uart/uart.h>

#define PORT_NAME "uart2"
#define BSP_CONFIG_NAME "rpi4_bcm2711.default"

#define KOS_COMMAND_MESSAGE_HEAD_SIZE 4

enum KOSCommandType {
    ERROR = 0x00,
    Command_ArmRequest = 0x3A,
    Command_ArmPermit = 0xA5,
    Command_ArmForbid = 0xE4,
    Command_AbortFlight = 0xAB
};

struct KOSCommandMessage {
    uint8_t head[KOS_COMMAND_MESSAGE_HEAD_SIZE];
    uint8_t command;

    KOSCommandMessage();
    KOSCommandMessage(KOSCommandType com);
};

int wait_for_ardupilot_request();
int send_command(KOSCommandType com);