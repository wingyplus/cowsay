project(cowsay_cli)

find_package(LibGoogleGFlags REQUIRED COMPONENTS nothread_static)

add_executable(cowsay main.cpp)
target_link_libraries(cowsay Cowsay::Lib gflags::gflags)
