cmake_minimum_required(VERSION 3.10)

project(fi_os)

file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/driver/*.c"
    "${PROJECT_SOURCE_DIR}/interface/*.c"
    "${PROJECT_SOURCE_DIR}/system/*.c"
    "${PROJECT_SOURCE_DIR}/main.c"
)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/lib"
    "${PROJECT_SOURCE_DIR}/include/internal"
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} wiringPi)
