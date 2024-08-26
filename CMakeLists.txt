cmake_minimum_required(VERSION 3.13)

set(picotool_DIR ~/picotool)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(fi-os)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/driver/*.c"
    "${PROJECT_SOURCE_DIR}/interface/pico.c"
    "${PROJECT_SOURCE_DIR}/system/*.c"
    "${PROJECT_SOURCE_DIR}/main.c"
)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/lib"
    "${PROJECT_SOURCE_DIR}/include/internal"
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${CMAKE_PROJECT_NAME} pico_stdlib)

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})
