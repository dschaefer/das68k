cmake_minimum_required(VERSION 3.8)
project(dasputer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(verilator HINTS ${VERILATOR_ROOT} $ENV{VERILATOR_ROOT})
if (NOT verilator_FOUND)
    message(FATAL_ERROR "Verilator not found")
endif()

add_library(das68k STATIC "")
verilate(das68k
    SOURCES das68k.v
    TOP_MODULE das68k
)

add_executable(dasputer sim_main.cpp)
target_link_libraries(dasputer PUBLIC das68k)

add_subdirectory(googletest)
add_subdirectory(test)
