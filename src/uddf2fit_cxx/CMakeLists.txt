cmake_minimum_required(VERSION 3.27)

project(
  uddf2fit_cxx
  LANGUAGES CXX
  VERSION 1.0.0)

find_package(garmin_fit_sdk CONFIG)
if(NOT garmin_fit_sdk_FOUND)
  add_subdirectory(${CMAKE_SOURCE_DIR}/../garmin_fit_sdk_cxx garmin_fit_sdk_cxx)
endif()

find_package(uddf_parser_cxx CONFIG REQUIRED)
if(NOT uddf_parser_cxx_FOUND)
  add_subdirectory(${CMAKE_SOURCE_DIR}/../uddf_parser_cxx uddf_parser_cxx)
endif()

add_executable(uddf2fit ${CMAKE_CURRENT_LIST_DIR}/src/uddf2fit.cpp)
target_include_directories(
  uddf2fit PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                  $<INSTALL_INTERFACE:include>)
target_link_libraries(uddf2fit PRIVATE uddf2fit::uddf_parser_cxx
                                       garmin::garmin_fit_sdk)

# ==================================================================================================

install(
  TARGETS uddf2fit
  EXPORT uddf2fit
  LIBRARY COMPONENT Runtime NAMELINK_COMPONENT Development
  RUNTIME COMPONENT Runtime
  ARCHIVE COMPONENT Development
          FILE_SET HEADERS
          COMPONENT Development)
install(
  EXPORT uddf2fit
  NAMESPACE uddf2fit::
  DESTINATION lib/cmake/uddf2fit)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/uddf2fit"
  NO_SET_AND_CHECK_MACRO NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/uddf2fitConfigVersion.cmake
        DESTINATION lib/cmake/uddf2fit)
