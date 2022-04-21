cmake_minimum_required(VERSION 3.20)
project(cowsay)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

find_package(LibUnicodeDisplayWidth REQUIRED)
find_package(LibGoogleGFlags REQUIRED COMPONENTS nothread_static)

add_executable(cowsay main.cpp)
target_link_libraries(cowsay UnicodeDisplayWidth::UnicodeDisplayWidth gflags::gflags)
