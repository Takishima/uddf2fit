# UDDF to FIT Converter

add_executable(uddf2fit ${CMAKE_CURRENT_LIST_DIR}/src/uddf2fit.cpp)

target_include_directories(
  uddf2fit
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(uddf2fit
  PRIVATE
    uddf_parser_cxx
    garmin_fit_sdk)

# Installation
install(
  TARGETS uddf2fit
  EXPORT uddf2fitTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
