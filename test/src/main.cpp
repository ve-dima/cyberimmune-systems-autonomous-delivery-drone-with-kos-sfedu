#include "../sdk/sdk_i2c.h"
#include <bsp/bsp.h>
#include <rtl/retcode_hr.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    Retcode rc = BspInit(RTL_NULL);
    fprintf(stderr, "Initializing BSP\n");
    if (rc != BSP_EOK) {
        fprintf(stderr, "BspInit() failed: "RETCODE_HR_FMT"\n", RETCODE_HR_PARAMS(rc));
        return EXIT_FAILURE;
    }

    if (!startI2C("i2c0"))
        return EXIT_FAILURE;

    if (!initializeCompass()) {
        fprintf(stderr, "Failed to initialize the compass\n");
        return EXIT_FAILURE;
    }

    calibrate();

    while (1) {
        fprintf(stderr, "Azimuth: %d\n", getAzimuth());
        sleep(1);
    }

    return EXIT_SUCCESS;
}
