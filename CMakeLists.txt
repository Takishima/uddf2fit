cmake_minimum_required(VERSION 3.27)

project(
  uddf2fit
  VERSION 0.1.0
  DESCRIPTION "UDDF to Garmin FIT file converter"
  LANGUAGES CXX)

# ==============================================================================
# Project options
# ==============================================================================

option(UDDF2FIT_BUILD_TESTS "Build unit tests" ON)
option(UDDF2FIT_BUILD_EXAMPLES "Build example programs" ON)

# ==============================================================================
# Global settings
# ==============================================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# ==============================================================================
# Dependencies
# ==============================================================================

find_package(PkgConfig REQUIRED)
pkg_check_modules(xerces-c REQUIRED IMPORTED_TARGET xerces-c)

# ==============================================================================
# Subdirectories
# ==============================================================================

add_subdirectory(src/garmin_fit_sdk_cxx)
add_subdirectory(src/uddf_parser_cxx)
add_subdirectory(src/uddf2fit_cxx)

# ==============================================================================
# Testing
# ==============================================================================

if(UDDF2FIT_BUILD_TESTS)
  enable_testing()
  # add_subdirectory(tests)  # TODO: Add when tests are implemented
endif()

# ==============================================================================
# Installation
# ==============================================================================

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
  EXPORT uddf2fitTargets
  FILE uddf2fitTargets.cmake
  NAMESPACE uddf2fit::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uddf2fit)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/uddf2fitConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uddf2fit)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/uddf2fit)
