cmake_minimum_required(VERSION 3.10)

project(fi_os)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

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
