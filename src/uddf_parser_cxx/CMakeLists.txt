# UDDF Parser C++ Library
# Generated from UDDF 3.2.3 XSD using xsdcxx

set(UDDF_PARSER_SOURCES
  ${CMAKE_CURRENT_LIST_DIR}/src/load.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/abundance.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/accommodationType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/acknowledge.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/addressType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/alarm.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/alarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/alcoholbeforedive.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/anysymptoms.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/apparatus.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/applicationdataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ascent.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/baseCalculationType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/batterychargecondition.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/bottomtimetablescopeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/bottomtimetableType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/buddy.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/buehlmannType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/builtType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/business.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/calculatebottomtimetable.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/calculateprofile.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/calculatetable.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/cameraType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/caveType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/certificationType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/contactType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/currency.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/current.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dateoftrip.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcalarmtimeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcalarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcalarmWithDepthType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcalarmWithTimeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcbuddydataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcdecomodelType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcdivedepthalarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcdivepo2alarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcdivesitedataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcdivetimealarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcendndtalarmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dcgasdefinitionsdataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/decomodel.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/decostop.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/decotrainer.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/descent.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dimensionType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divebaseType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divecomputercontrol.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divecomputerdumpType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/diveinsurances.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divemode.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divemodeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divepermissions.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/diveplan.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/diver.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divesite.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divetable.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/divetrip.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/diveType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/dominance.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/drugType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ecologyType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/education.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/encapsulatedDateTimeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/environment.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/equipmentconfigurationType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/equipmentmalfunction.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/equipmentPieceType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/equipmentType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/equipmentused.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/examinationresult.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/examinationType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/exposuretoaltitudeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/faunaType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/floraType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/gas.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/gasdefinitions.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/generator.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/geographyType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/getdcdataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/globalalarm.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/globalalarmsgiven.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/globallightintensityType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/gradientfactor.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/guideType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/hargikas.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/heinrichsweikamp.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ID.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/IDREF.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ID_TYPE.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/imagedata.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/imageType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/individualType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/indoorType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/infinity.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/informationafterdiveType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/informationbeforediveType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/inputprofileType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/instructorType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/insuranceType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/invertebrataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/kind.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/lifestage.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/lightintensityType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/linkType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/maker.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/manufacturerType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/markerType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/measuredpo2.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/mediadata.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/mediaType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/medicalbeforedive.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/medical.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/membership.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/meteringmethod.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/mixchangeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/mixType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/namedType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/nosuit.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/notesType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/numberofdives.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/observationsType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/occurence.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/operatorType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/outputType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/periodicallytaken.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/permitType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/personalType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/personType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/placeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/platform.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/priceperdivepackageType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/priceType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/problems.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/profiledata.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/program.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/purchaseType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/purpose.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/quality.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ratingType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/ratingvalueType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/rebreatherType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/relateddives.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/repetitiongroupType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/rgbmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/samplesType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/setby.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/setdcdataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/setpo2.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/sexType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/shopType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/simpleNamedType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/singleLifeFormType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/sitedataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/siteType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/smoking.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/speciesType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/stateofrestbeforedive.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/suittype1.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/suitType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/surfaceintervalType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tablegeneration.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tablescopeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tableType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tankdataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tankmaterialType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tankpressure.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tankType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tausim.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tautabu.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/thermalcomfort.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tissueType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/transportation.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/trippartType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/tripType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/type.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/uddf_3.2.3.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/uddf.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/vertebrataType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/vesselType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/videocameraType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/vpmType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/wayaltitudeType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/waypointType.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/workload.cxx
  ${CMAKE_CURRENT_LIST_DIR}/src/wreckType.cxx)

add_library(uddf_parser_cxx ${UDDF_PARSER_SOURCES})
add_library(uddf2fit::uddf_parser ALIAS uddf_parser_cxx)

target_include_directories(
  uddf_parser_cxx
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/uddf2fit>
         $<INSTALL_INTERFACE:include>
         $<INSTALL_INTERFACE:include/uddf2fit>)

target_link_libraries(uddf_parser_cxx
  PUBLIC
    XercesC::XercesC
    libxsd_headers)

set_target_properties(uddf_parser_cxx PROPERTIES
  POSITION_INDEPENDENT_CODE ON)

# Installation
install(
  TARGETS uddf_parser_cxx
  EXPORT uddf2fitTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
