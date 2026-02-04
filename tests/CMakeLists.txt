# Tests for uddf2fit

# Create a library with the testable code (excluding main)
add_library(uddf2fit_lib STATIC
  ${CMAKE_SOURCE_DIR}/src/uddf2fit_cxx/src/conversions.cpp
  ${CMAKE_SOURCE_DIR}/src/uddf2fit_cxx/src/dive_stats.cpp
  ${CMAKE_SOURCE_DIR}/src/uddf2fit_cxx/src/fit_writer.cpp)

target_include_directories(uddf2fit_lib
  PUBLIC ${CMAKE_SOURCE_DIR}/src/uddf2fit_cxx/include)

target_link_libraries(uddf2fit_lib
  PUBLIC garmin_fit_sdk)

# Test executable
add_executable(uddf2fit_tests
  test_conversions.cpp
  test_dive_stats.cpp)

target_link_libraries(uddf2fit_tests
  PRIVATE
    uddf2fit_lib
    Catch2::Catch2WithMain)

# Register tests with CTest
catch_discover_tests(uddf2fit_tests)
