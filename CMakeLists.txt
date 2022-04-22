cmake_minimum_required(VERSION 3.20)
project(cowsay)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(libcowsay)
add_subdirectory(cowsay_cli)