#include "../sdk/sdk_net.h"
#include "../sdk/sdk_gpio.h"
#include "../sdk/sdk_uart.h"
#include <bsp/bsp.h>
#include <rtl/retcode_hr.h>
#include <unistd.h>

#define SERVER_ASK_PERIOD_S 1
std::string server_address = "192.168.0.105";

int main(int argc, char* argv[]) {
    fprintf(stderr, "Initializing network connection\n");
    if (!wait_for_network())
    {
        fprintf(stderr, "Failed to connect to network\n");
        return EXIT_FAILURE;
    }
    fprintf(stderr, "Network connection is established\n");

    Retcode rc = BspInit(RTL_NULL);
    fprintf(stderr, "Initializing BSP\n");
    if (rc != BSP_EOK) {
        fprintf(stderr, "BspInit() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }
    fprintf(stderr, "BSP is initialized\n");

    fprintf(stderr, "Initializing GPIO\n");
    if (!startGPIO())
        return EXIT_FAILURE;
    fprintf(stderr, "GPIO is initialized\n");

    fprintf(stderr, "Initializing UART\n");
    if (!startUART())
        return EXIT_FAILURE;
    fprintf(stderr, "UART is initialized\n");

    if (!setLight(false))
        return EXIT_FAILURE;
    fprintf(stderr, "All modules are initialized\n");

    /*std::string server_response;
    if (!get_request(server_address, 80, "auth?id=1", server_response))
        return EXIT_FAILURE;
    fprintf(stderr, "Authentication message is sent to the server\n");*/

    fprintf(stderr, "Waiting for an arm...\n");

    if (!wait_for_ardupilot_request()) {
        fprintf(stderr, "Error in waiting for ardupilot arm-request\n");
        return EXIT_FAILURE;
    }

    startBlinking();
    fprintf(stderr, "Request for server is sent. Waiting for response...\n");

    sleep(10);
    /*server_response = "";
    if (!get_request(server_address, 80, "arm?id=1", server_response))
        return EXIT_FAILURE;
    fprintf(stderr, "Server response is received\n");*/

    //if (server_response.find("Arm: 0 ") != -1) {
        stopBlinking();
        if (!setLight(true))
            return EXIT_FAILURE;
        fprintf(stderr, "Response from the server is received: arm is permitted\n");
        if (!send_command(KOSCommandType::Command_ArmPermit))
            return EXIT_FAILURE;
        fprintf(stderr, "Arm permit is passed to ardupilot\n");
    /*}
    else if (server_response.find("Arm: 1 ") != -1) {
        stopBlinking();
        if (!setLight(false))
            return EXIT_FAILURE;
        fprintf(stderr, "Response from the server is received: arm is prohibited\n");
        if (!send_command(KOSCommandType::Command_ArmForbid))
            return EXIT_FAILURE;
            fprintf(stderr, "Arm prohibition is passed to ardupilot\n");
        return EXIT_SUCCESS;
    }
    else {
        fprintf(stderr, "Failed to parse server response\n");
        return EXIT_FAILURE;
    }*/

    sleep(10);
    /*while(1) {
        server_response = "";
        if (!get_request(server_address, 80, "fly_accept?id=1", server_response))
            return EXIT_FAILURE;
        
        if (server_response.find("Arm: 0 ") != -1) {
            //Continue fligt
        }
        else if (server_response.find("Arm: 1 ") != -1) {*/
            fprintf(stderr, "A request to stop the flight was received from the server\n");
            if (!setLight(false))
                return EXIT_FAILURE;
            if (!send_command(KOSCommandType::Command_AbortFlight))
                return EXIT_FAILURE;
            fprintf(stderr, "A request to stop flight is passed to ardupilot\n");
            return EXIT_SUCCESS;
    /*    }
        else {
            fprintf(stderr, "Failed to parse server response\n");
            return EXIT_FAILURE;
        }
        sleep(SERVER_ASK_PERIOD_S);
    };*/

    return EXIT_SUCCESS;
}
