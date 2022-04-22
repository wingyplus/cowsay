project(libcowsay)

find_package(LibUnicodeDisplayWidth REQUIRED)
find_package(LibGoogleTest REQUIRED)

add_library(libcowsay src/cowsay.cpp)
target_include_directories(libcowsay PUBLIC include)
target_link_libraries(libcowsay UnicodeDisplayWidth::UnicodeDisplayWidth)
add_library(Cowsay::Lib ALIAS libcowsay)

enable_testing()

add_executable(libcowsay_test test/cowsay_test.cpp)
target_link_libraries(libcowsay_test Cowsay::Lib gtest_main)

include(GoogleTest)
gtest_discover_tests(libcowsay_test)