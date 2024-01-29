#include "../sdk/fcc.h"
#include "../sdk/ardupilot.h"
#include <bsp/bsp.h>
#include <rtl/retcode_hr.h>

#define DELAY_S 1

std::string server_address = "192.168.0.108";

bool startUART() {
    Retcode rc = BspInit(RTL_NULL);
    if (rc != BSP_EOK) {
        fprintf(stderr, "BspInit() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }
    rc = BspEnableModule(PORT_NAME);
    if (rc != BSP_EOK) {
        fprintf(stderr, "BspEnableModule() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }
    rc = BspSetConfig(PORT_NAME, BSP_CONFIG_NAME);
    if (rc != BSP_EOK) {
        fprintf(stderr, "BspSetConfig() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }
    rc = UartInit();
    if (rc != UART_EOK) {
        fprintf(stderr, "UartInit() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "Initializing network connection\n");
    /*if (!wait_for_network())
    {
        fprintf(stderr, "Failed to connect to network\n");
        return EXIT_FAILURE;
    }*/
    fprintf(stderr, "Network connection is established\n");

    //std::string server_response;
    //if (!get_request(server_address, 80, "auth?id=1", server_response))
    //    return EXIT_FAILURE;

    fprintf(stderr, "Initializing UART\n");
    if (!startUART())
        return EXIT_FAILURE;

    fprintf(stderr, "All modules are initialized\n");

    if (!wait_for_ardupilot_request()) {
        fprintf(stderr, "Error in waiting for ardupilot arm-request\n");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "Request for server is sent. Waiting for response...\n");
    //server_response = "";
    //if (!get_request(server_address, 80, "arm?id=1", server_response))
    //    return EXIT_FAILURE;
    sleep(10);

    //if (server_response.find("Arm: 0 ") != -1) {
        fprintf(stderr, "Response from the server is received: arm is permitted\n");
        send_command(KOSCommandType::Command_ArmPermit);
    /*}
    else if (server_response.find("Arm: 1 ") != -1) {
        fprintf(stderr, "Response from the server is received: arm is forbidden\n");
        send_command(KOSCommandType::Command_ArmForbid);
        return EXIT_SUCCESS;
    }
    else {
        fprintf(stderr, "Failed to parse server response\n");
        return EXIT_FAILURE;
    }*/

    sleep(10);

    //while(1) {
        //server_response = "";
        //if (!get_request(server_address, 80, "fly_accept?id=1", server_response))
        //    return EXIT_FAILURE;
        
        //if (server_response.find("Arm: 0 ") != -1) {
            //Continue fligt
        //}
        //else if (server_response.find("Arm: 1 ") != -1) {
            fprintf(stderr, "An instruction to stop the flight was received from the server. Disarming...\n");
            send_command(KOSCommandType::Command_AbortFlight);
            return EXIT_SUCCESS;
        //}
        //else {
        //    fprintf(stderr, "Failed to parse server response\n");
        //    return EXIT_FAILURE;
        //}
        //sleep(DELAY_S);
    //};

    return EXIT_SUCCESS;
}
