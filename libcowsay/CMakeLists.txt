project(libcowsay)

find_package(LibUnicodeDisplayWidth REQUIRED)

add_library(libcowsay src/cowsay.cpp)
target_include_directories(libcowsay PUBLIC include)
target_link_libraries(libcowsay UnicodeDisplayWidth::UnicodeDisplayWidth)
add_library(Cowsay::Lib ALIAS libcowsay)