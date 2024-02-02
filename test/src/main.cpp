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

    if (!startI2C("i2c1"))
        return EXIT_FAILURE;

    if (!initializeMPU()) {
        fprintf(stderr, "Failed to initialize the MPU\n");
        return EXIT_FAILURE;
    }

    calibrateGyro();

    while (1) {
        Vector3f acc = getAcceleration();
        fprintf(stderr, "Acceleration: %f, %f, %f\n", acc.X, acc.Y, acc.Z);
        Vector3f gyro = getGyro();
        fprintf(stderr, "Gyro: %f, %f, %f\n", gyro.X, gyro.Y, gyro.Z);
        fprintf(stderr, "Temperature: %f\n\n", getTemperature());
        sleep(1);
    }

    return EXIT_SUCCESS;
}
