# UDDF to FIT Converter

# Select the appropriate main source file based on parser backend
if(UDDF2FIT_PARSER STREQUAL "xsdcxx")
  set(UDDF2FIT_MAIN_SRC ${CMAKE_CURRENT_LIST_DIR}/src/uddf2fit.cpp)
  set(UDDF_PARSER_TARGET uddf_parser_cxx)
elseif(UDDF2FIT_PARSER STREQUAL "uxsdcxx")
  set(UDDF2FIT_MAIN_SRC ${CMAKE_CURRENT_LIST_DIR}/src/uddf2fit_pugi.cpp)
  set(UDDF_PARSER_TARGET uddf_parser_pugi)
endif()

add_executable(uddf2fit
  ${UDDF2FIT_MAIN_SRC}
  ${CMAKE_CURRENT_LIST_DIR}/src/conversions.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/dive_stats.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/fit_writer.cpp)

target_include_directories(
  uddf2fit
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(uddf2fit
  PRIVATE
    ${UDDF_PARSER_TARGET}
    garmin_fit_sdk)

# Installation
install(
  TARGETS uddf2fit
  EXPORT uddf2fitTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
