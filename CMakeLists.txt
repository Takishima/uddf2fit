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

# Parser backend selection: xsdcxx (requires xerces-c) or uxsdcxx (uses pugixml)
set(UDDF2FIT_PARSER "xsdcxx" CACHE STRING "UDDF parser backend: xsdcxx or uxsdcxx")
set_property(CACHE UDDF2FIT_PARSER PROPERTY STRINGS "xsdcxx" "uxsdcxx")

# Validate parser selection
if(NOT UDDF2FIT_PARSER STREQUAL "xsdcxx" AND NOT UDDF2FIT_PARSER STREQUAL "uxsdcxx")
  message(FATAL_ERROR "UDDF2FIT_PARSER must be either 'xsdcxx' or 'uxsdcxx'")
endif()

message(STATUS "Using UDDF parser backend: ${UDDF2FIT_PARSER}")

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

include(FetchContent)

if(UDDF2FIT_PARSER STREQUAL "xsdcxx")
  # xsdcxx backend: requires xerces-c and libxsd runtime

  # Fetch libxsd (header-only runtime library for xsdcxx-generated code)
  FetchContent_Declare(
    libxsd
    GIT_REPOSITORY https://github.com/codesynthesis-com/libxsd.git
    GIT_TAG master
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(libxsd)

  # Create a header-only interface target for libxsd
  add_library(libxsd_headers INTERFACE)
  target_include_directories(libxsd_headers INTERFACE ${libxsd_SOURCE_DIR})

  # Try to find system xerces-c first, otherwise fetch from source
  find_package(XercesC QUIET)
  if(NOT XercesC_FOUND)
    message(STATUS "XercesC not found on system, fetching from source...")
    FetchContent_Declare(
      XercesC
      GIT_REPOSITORY https://github.com/apache/xerces-c.git
      GIT_TAG v3.2.5
      GIT_SHALLOW TRUE
    )
    # Set xerces-c options before making it available
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    set(network-accessor "socket" CACHE STRING "" FORCE)
    set(transcoder "iconv" CACHE STRING "" FORCE)
    set(message-loader "inmemory" CACHE STRING "" FORCE)
    set(mutex-manager "standard" CACHE STRING "" FORCE)
    FetchContent_MakeAvailable(XercesC)

    # Create an alias target to match our usage
    if(TARGET xerces-c)
      add_library(XercesC::XercesC ALIAS xerces-c)
    endif()
  else()
    message(STATUS "Found system XercesC: ${XercesC_VERSION}")
  endif()
elseif(UDDF2FIT_PARSER STREQUAL "uxsdcxx")
  # uxsdcxx backend: uses pugixml (lightweight, header-only friendly)
  FetchContent_Declare(
    pugixml
    GIT_REPOSITORY https://github.com/zeux/pugixml.git
    GIT_TAG v1.14
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(pugixml)
endif()

# ==============================================================================
# Subdirectories
# ==============================================================================

add_subdirectory(src/garmin_fit_sdk_cxx)

if(UDDF2FIT_PARSER STREQUAL "xsdcxx")
  add_subdirectory(src/uddf_parser_cxx)
elseif(UDDF2FIT_PARSER STREQUAL "uxsdcxx")
  add_subdirectory(src/uddf_parser_pugi)
endif()

add_subdirectory(src/uddf2fit_cxx)

# ==============================================================================
# Testing
# ==============================================================================

if(UDDF2FIT_BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
    FIND_PACKAGE_ARGS
  )
  FetchContent_MakeAvailable(Catch2)

  # Add Catch2 CMake module path (for catch_discover_tests)
  if(catch2_SOURCE_DIR)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
  endif()

  enable_testing()
  include(CTest)
  include(Catch)
  add_subdirectory(tests)
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
