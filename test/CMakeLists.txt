project (test)

# Toolchain for working with the NK-parser.
include (platform/nk)

# Set compiler flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:YES")

nk_build_edl_files (test_edl_files NK_MODULE "sdk" EDL "${CMAKE_SOURCE_DIR}/resources/Test.edl")

add_executable (Test "src/main.cpp" "sdk/sdk_i2c.h" "sdk/sdk_i2c.cpp" ${EDL_FILES})
add_dependencies (Test test_edl_files)
target_compile_features (Test PRIVATE cxx_std_17)
target_compile_definitions (Test PRIVATE "-DBOARD_CONFIG=\"${BOARD_NAME}\"")

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm|aarch64")
    target_link_libraries (Test ${bsp_CLIENT_LIB})
endif ()

target_link_libraries (Test ${gpio_CLIENT_LIB} ${i2c_CLIENT_LIB})