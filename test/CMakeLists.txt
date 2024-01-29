project (test)

# Toolchain for working with the NK-parser.
include (platform/nk)

# Set compiler flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:YES")

nk_build_edl_files (test_edl_files NK_MODULE "client" EDL "${CMAKE_SOURCE_DIR}/resources/Test.edl")

add_executable (Test "src/main.cpp" "sdk/fcc.h" "sdk/fcc.cpp" "sdk/ardupilot.h" "sdk/ardupilot.cpp" ${EDL_FILES})
add_dependencies (Test test_edl_files)
target_compile_features (Test PRIVATE cxx_std_17)

target_link_libraries (Test ${gpio_CLIENT_LIB})
target_link_libraries (Test ${uart_CLIENT_LIB})

find_package (Threads)
target_link_libraries (Test ${CMAKE_THREAD_LIBS_INIT})

if ("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "arm|aarch64")
    target_link_libraries (Test ${bsp_CLIENT_LIB})
endif ()


#target_link_libraries (Test
#    ${vfs_CLIENT_LIB}
#    ${wpa_CLIENT_LIB}
#    iperf m
#)