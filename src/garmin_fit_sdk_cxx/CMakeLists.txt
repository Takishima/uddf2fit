# Garmin FIT SDK C++ Library

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
  POSITION_INDEPENDENT_CODE ON)

# Example executables
if(UDDF2FIT_BUILD_EXAMPLES)
  add_executable(fit_decode_example ${CMAKE_CURRENT_LIST_DIR}/src/decode.cpp)
  target_link_libraries(fit_decode_example PRIVATE garmin_fit_sdk)

  add_executable(fit_encode_example ${CMAKE_CURRENT_LIST_DIR}/src/encode.cpp)
  target_link_libraries(fit_encode_example PRIVATE garmin_fit_sdk)
endif()

# Installation
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
