cmake_minimum_required(VERSION 3.20)
project(cowsay)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_library(unicode_display_width INTERFACE)
target_include_directories(unicode_display_width INTERFACE third_party/unicode_display_width/include)

add_executable(cowsay main.cpp)
target_link_libraries(cowsay unicode_display_width)
