# UDDF to FIT Converter
# Main executable for converting UDDF dive logs to Garmin FIT format

cmake_minimum_required(VERSION 3.27)

if(NOT PROJECT_NAME)
  project(
    uddf2fit_cxx
    LANGUAGES CXX
    VERSION 1.0.0)
  set(UDDF2FIT_STANDALONE TRUE)

  # When building standalone, we need to find/build dependencies
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(xerces-c REQUIRED IMPORTED_TARGET xerces-c)

  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../garmin_fit_sdk_cxx
                   ${CMAKE_BINARY_DIR}/garmin_fit_sdk_cxx)
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../uddf_parser_cxx
                   ${CMAKE_BINARY_DIR}/uddf_parser_cxx)
endif()

# ==============================================================================
# Main executable
# ==============================================================================

add_executable(uddf2fit ${CMAKE_CURRENT_LIST_DIR}/src/uddf2fit.cpp)

target_include_directories(
  uddf2fit
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(uddf2fit
  PRIVATE
    uddf_parser_cxx
    garmin_fit_sdk)

set_target_properties(uddf2fit PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON)

# ==============================================================================
# Installation
# ==============================================================================

include(GNUInstallDirs)

install(
  TARGETS uddf2fit
  EXPORT uddf2fitTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
