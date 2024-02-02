project (einit)

# Tools for working with KasperskyOS images.
include (platform/image)
include (${KL_SDK_ROOT_PATH}/common/build-sd-image.cmake)

# Set compile flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:YES")

# KasperskyOS image for the target hardware platform.
build_kos_hw_image (kos-image
                    EINIT_ENTITY EinitHw
                    CONNECTIONS_CFG "init.yaml.in"
                    SECURITY_PSL "security.psl.in"
                    Test)

# SD card image with KasperskyOS for the target hardware platform.
build_sd_image (sd-image
                KOS_IMAGE_TARGET kos-image)