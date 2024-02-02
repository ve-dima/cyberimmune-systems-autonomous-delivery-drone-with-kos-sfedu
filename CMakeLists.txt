cmake_minimum_required (VERSION 3.12)

project (mav_sdk)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform (FORCE_STATIC)

if (PLATFORM_SUPPORTS_DYNAMIC_LINKING)
    message (FATAL_ERROR "The solution only supports static libraries")
endif ()

# Toolchain for working with the NK-parser.
include (platform/nk)

# Add functions for installing artefacts.
include (platform/install)

find_package (bsp REQUIRED)
include_directories (${bsp_INCLUDE})

find_package (i2c REQUIRED)
include_directories (${i2c_INCLUDE})

# Recommended flags against vulnerabilities.
add_compile_options (-Wall -Wextra -Wconversion
                     -fPIE -pie -D_FORTIFY_SOURCE=2 -O2
                     -fstack-protector-strong -fstack-clash-protection
                     -mbranch-protection=standard
                     -Wsign-conversion -Wformat=2 -Wformat-security -Werror=format-security
                     -fsanitize=undefined -fsanitize-undefined-trap-on-error)

add_link_options (LINKER:-z,noexecstack
                  LINKER:-z,separate-code
                  LINKER:-z,now)

add_subdirectory (test)
add_subdirectory (einit)
