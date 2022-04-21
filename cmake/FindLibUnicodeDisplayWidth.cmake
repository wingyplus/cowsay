include(FetchContent)

FetchContent_Declare(
  unicode_display_width
  GIT_REPOSITORY https://github.com/p-ranav/unicode_display_width.git
  GIT_TAG 6c964711e04ebf0127b97fb6c66606315e235953
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
)

FetchContent_MakeAvailable(unicode_display_width)

add_library(unicode_display_width INTERFACE)
target_include_directories(unicode_display_width INTERFACE ${unicode_display_width_SOURCE_DIR}/include)

add_library(UnicodeDisplayWidth::UnicodeDisplayWidth ALIAS unicode_display_width)