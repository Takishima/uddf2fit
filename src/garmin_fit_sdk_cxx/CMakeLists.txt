# Garmin FIT SDK C++ Library
# Can be built standalone or as part of the uddf2fit project

cmake_minimum_required(VERSION 3.27)

if(NOT PROJECT_NAME)
  project(
    garmin_fit_sdk
    LANGUAGES CXX
    VERSION 1.0.0)
  set(GARMIN_FIT_SDK_STANDALONE TRUE)
endif()

# ==============================================================================
# Library
# ==============================================================================

add_library(
  garmin_fit_sdk
  ${CMAKE_CURRENT_LIST_DIR}/src/fit.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_accumulated_field.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_accumulator.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_buffered_mesg_broadcaster.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_buffered_record_mesg_broadcaster.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_crc.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_date_time.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_decode.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field_definition.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field_description.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_encode.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_field.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_field_base.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_field_definition.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_broadcaster.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_definition.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_with_event_broadcaster.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_profile.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_protocol_validator.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_unicode.cpp)

add_library(garmin::fit_sdk ALIAS garmin_fit_sdk)

target_include_directories(
  garmin_fit_sdk
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

set_target_properties(garmin_fit_sdk PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  POSITION_INDEPENDENT_CODE ON)

# ==============================================================================
# Example executables (only in standalone mode or when examples enabled)
# ==============================================================================

if(GARMIN_FIT_SDK_STANDALONE OR UDDF2FIT_BUILD_EXAMPLES)
  add_executable(fit_decode_example ${CMAKE_CURRENT_LIST_DIR}/src/decode.cpp)
  target_link_libraries(fit_decode_example PRIVATE garmin_fit_sdk)

  add_executable(fit_encode_example ${CMAKE_CURRENT_LIST_DIR}/src/encode.cpp)
  target_link_libraries(fit_encode_example PRIVATE garmin_fit_sdk)
endif()

# ==============================================================================
# Installation
# ==============================================================================

include(GNUInstallDirs)

install(
  TARGETS garmin_fit_sdk
  EXPORT uddf2fitTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
