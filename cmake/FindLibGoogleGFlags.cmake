include(FetchContent)

FetchContent_Declare(
  gflags
  GIT_REPOSITORY https://github.com/gflags/gflags.git
  GIT_TAG 986e8eed00ded8168ef4eaa6f925dc6be50b40fa
)

FetchContent_MakeAvailable(gflags)