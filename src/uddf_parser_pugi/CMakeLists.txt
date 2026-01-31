# UDDF Parser using PugiXML
# Lightweight alternative to xsdcxx/xerces-c

add_library(uddf_parser_pugi
  ${CMAKE_CURRENT_LIST_DIR}/src/uddf_parser.cpp)

add_library(uddf2fit::uddf_parser ALIAS uddf_parser_pugi)

target_include_directories(
  uddf_parser_pugi
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(uddf_parser_pugi PUBLIC pugixml::pugixml)

set_target_properties(uddf_parser_pugi PROPERTIES
  POSITION_INDEPENDENT_CODE ON)

# Installation
install(
  TARGETS uddf_parser_pugi
  EXPORT uddf2fitTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
