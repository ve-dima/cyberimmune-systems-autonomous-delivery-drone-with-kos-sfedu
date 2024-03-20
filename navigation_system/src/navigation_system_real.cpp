#include "../include/navigation_system.h"
#include "../../ipc_messages/include/initialization_interface.h"

#include <coresrv/hal/hal_api.h>
#include <rtl/retcode_hr.h>
#include <uart/uart.h>
#include <bsp/bsp.h>

#include <stdio.h>
#include <unistd.h>

#define NAME_MAX_LENGTH 64
#define RETRY_DELAY_SEC 1

char gpsUart[] = "uart2";
char gpsConfigSuffix[] = "default";
UartHandle gpsUartHandler = NULL;

int32_t simLatitude = 0;
int32_t simLongitude = 0;
float simAltitude = 0;

void getSensors() {
    while (true) {
        uint8_t value;
        Retcode rc = UartReadByte(gpsUartHandler, &value);
        if (rc != rcOk) {
            fprintf(stderr, "[%s] Warning: Failed to read from UART %s ("RETCODE_HR_FMT")\n", ENTITY_NAME, gpsUart, RETCODE_HR_PARAMS(rc));
            continue;
        }
        fprintf(stderr, "[%s] byte: %c\n", ENTITY_NAME, value);
    }
}

int initNavigationSystem() {
    /*if (!waitForInit("ns_pc_connection", "PeripheryController")) {
        fprintf(stderr, "[%s] Warning: Failed to receive initialization notification from Periphery Controller. Trying again in %ds\n", ENTITY_NAME, RETRY_DELAY_SEC);
        sleep(RETRY_DELAY_SEC);
    }*/

    char boardName[NAME_MAX_LENGTH] = {0};
    if (KnHalGetEnv("board", boardName, sizeof(boardName)) != rcOk) {
        fprintf(stderr, "[%s] Error: Failed to get board name\n", ENTITY_NAME);
        return 0;
    }

    char gpsConfig[NAME_MAX_LENGTH];
    if (snprintf(gpsConfig, NAME_MAX_LENGTH, "%s.%s", boardName, gpsConfigSuffix) < 0) {
        fprintf(stderr, "[%s] Error: Failed to generate UART config name\n", ENTITY_NAME);
        return 0;
    }

    Retcode rc = BspInit(NULL);
    if (rc != rcOk) {
        fprintf(stderr, "[%s] Error: Failed to initialize BSP ("RETCODE_HR_FMT")\n", ENTITY_NAME, RETCODE_HR_PARAMS(rc));
        return 0;
    }
    rc = BspSetConfig(gpsUart, gpsConfig);
    if (rc != rcOk) {
        fprintf(stderr, "[%s] Error: Failed to set BSP config for UART %s ("RETCODE_HR_FMT")\n", ENTITY_NAME, gpsUart, RETCODE_HR_PARAMS(rc));
        return 0;
    }
    rc = UartInit();
    if (rc != rcOk) {
        fprintf(stderr, "[%s] Error: Failed to initialize UART ("RETCODE_HR_FMT")\n", ENTITY_NAME, RETCODE_HR_PARAMS(rc));
        return 0;
    }

    return 1;
}

int initSensors() {
    Retcode rc = UartOpenPort(gpsUart, &gpsUartHandler);
    if (rc != rcOk) {
        fprintf(stderr, "[%s] Warning: Failed to open UART %s ("RETCODE_HR_FMT")\n", ENTITY_NAME, gpsUart, RETCODE_HR_PARAMS(rc));
        return 0;
    }

    return 1;
}

int getCoords(int32_t &latitude, int32_t &longitude, float &altitude) {
    //Not implemented yet

    return 1;
}