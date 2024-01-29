#include "ardupilot.h"

#include <stdio.h>
#include <rtl/retcode_hr.h>
#include <uart/uart.h>

static const uint8_t command_message_head[KOS_COMMAND_MESSAGE_HEAD_SIZE] = { 0x7a, 0xfe, 0xf0, 0x0d };

KOSCommandMessage::KOSCommandMessage() {
    for (int i = 0; i < KOS_COMMAND_MESSAGE_HEAD_SIZE; i++)
        head[i] = 0;
    command = KOSCommandType::ERROR;
}

KOSCommandMessage::KOSCommandMessage(KOSCommandType com) {
    memcpy(head, command_message_head, KOS_COMMAND_MESSAGE_HEAD_SIZE);
    command = (uint8_t)com;
}

int wait_for_ardupilot_request() {
    UartHandle uartH = KDF_INVALID_HANDLE;
    Retcode rc = UartOpenPort(PORT_NAME, &uartH);
    if (rc != UART_EOK) {
        fprintf(stderr, "UartOpenPort() %s failed: "RETCODE_HR_FMT"\n", PORT_NAME, RETCODE_HR_PARAMS(rc));
        return 0;
    }

    //TEST
    while (1) {
        uint8_t rcv;
        rc = UartReadByte(uartH, &rcv);
        if (rc != UART_EOK) {
            fprintf(stderr, "UartReadByte is failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
            UartClosePort(uartH);
            return 0;
        }
        fprintf(stderr, "Read: %c\n", rcv);
    }
    //

    UartClosePort(uartH);
    return 1;
}

int send_command(KOSCommandType com) {
    UartHandle uartH = KDF_INVALID_HANDLE;
    Retcode rc = UartOpenPort(PORT_NAME, &uartH);
    if (rc != UART_EOK) {
        fprintf(stderr, "UartOpenPort() %s failed: "RETCODE_HR_FMT"\n", PORT_NAME, RETCODE_HR_PARAMS(rc));
        return 0;
    }

    KOSCommandMessage command = KOSCommandMessage(com);
    uint8_t message[sizeof(KOSCommandMessage)];
    memcpy(message, &command, sizeof(KOSCommandMessage));
    for (int i = 0; i < sizeof(KOSCommandMessage); i++) {
        rc = UartWriteByte(uartH, message[i]);
        if (rc != UART_EOK) {
            fprintf(stderr, "UartWriteByte is failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
            UartClosePort(uartH);
            return 0;
        }
    }

    UartClosePort(uartH);
    return 1;
}