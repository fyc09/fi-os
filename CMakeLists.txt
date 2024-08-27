cmake_minimum_required(VERSION 3.13)

set(picotool_DIR ~/picotool)

find_package(PythonInterp REQUIRED)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(fi-os)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/app/dino/pics.c"
    "${PROJECT_SOURCE_DIR}/app/home/ui.c"
    "${PROJECT_SOURCE_DIR}/driver/keyboard.c"
    "${PROJECT_SOURCE_DIR}/driver/oled.c"
    "${PROJECT_SOURCE_DIR}/driver/sd.c"
    "${PROJECT_SOURCE_DIR}/interface/pico.c"
    "${PROJECT_SOURCE_DIR}/main.c"
    "${PROJECT_SOURCE_DIR}/system/boot.c"
    "${PROJECT_SOURCE_DIR}/system/font.c"
    "${PROJECT_SOURCE_DIR}/system/fs.c"
)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/lib"
    "${PROJECT_SOURCE_DIR}/include/internal"
)

add_custom_command(
    OUTPUT "${PROJECT_SOURCE_DIR}/app/dino/pics.c"
    COMMAND "${PYTHON_EXECUTABLE}" "${PROJECT_SOURCE_DIR}/script/matrix/maker.py" "${PROJECT_SOURCE_DIR}/script/matrix/dino/info.txt" "${PROJECT_SOURCE_DIR}/script/matrix/dino/draw.bmp" "${PROJECT_SOURCE_DIR}/app/dino/pics.c" "dino"
    DEPENDS "${PROJECT_SOURCE_DIR}/script/matrix/maker.py" "${PROJECT_SOURCE_DIR}/script/matrix/dino/info.txt" "${PROJECT_SOURCE_DIR}/script/matrix/dino/draw.bmp"
    COMMENT "Generating /app/dino/pics.c"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/script/matrix"
)

add_custom_target(
    generate_dino
    DEPENDS "${PROJECT_SOURCE_DIR}/app/dino/pics.c"
)

# Enable all errors
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${CMAKE_PROJECT_NAME} pico_stdlib)

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})
