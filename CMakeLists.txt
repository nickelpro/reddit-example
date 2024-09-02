cmake_minimum_required(VERSION 3.30)

project(
  reddit-example
  LANGUAGES CXX
  VERSION 0.0.1
)

add_library(Util OBJECT)
target_compile_features(Util PRIVATE cxx_std_23)

add_library(Main)
target_compile_features(Main PRIVATE cxx_std_23)
target_sources(Main
  PRIVATE $<TARGET_OBJECTS:Util>
  PRIVATE FILE_SET util_headers
  TYPE HEADERS
  BASE_DIRS $<TARGET_PROPERTY:Util,INTERFACE_INCLUDE_DIRECTORIES>
)

add_subdirectory(src)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/reddit-example-config-version.cmake
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/reddit-example-config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/reddit-example-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_DATADIR}/reddit-example
)

install(
  TARGETS Main
  EXPORT reddit-example-targets
  FILE_SET HEADERS
)

install(
  EXPORT reddit-example-targets
  NAMESPACE rde::
  DESTINATION ${CMAKE_INSTALL_DATADIR}/reddit-example
)
