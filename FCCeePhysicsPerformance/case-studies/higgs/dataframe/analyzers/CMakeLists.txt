
find_package(ROOT REQUIRED COMPONENTS ROOTDataFrame ROOTVecOps)
include(${ROOT_USE_FILE})
#include("${ROOT_DIR}/modules/RootNewMacros.cmake")

find_package(EDM4HEP)
find_package(podio)
find_package(Vdt)
find_package(FastJet)


set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

get_target_property(EDM4HEP_INCLUDE_DIRS EDM4HEP::edm4hep INTERFACE_INCLUDE_DIRECTORIES)

include_directories(${EDM4HEP_INCLUDE_DIRS} ${podio_INCLUDE_DIR} ${VDT_INCLUDE_DIR} ${FASTJET_INCLUDE_DIR})

ROOT_GENERATE_DICTIONARY(G__FCCAnalysesHiggs 
                dummyLoaderHiggs.h
                APCHiggsTools.h
                LLRHiggsTools.h
                LINKDEF LinkDef.h)


file(GLOB sources *.cc)
file(GLOB headers *.h)
add_library(FCCAnalysesHiggs SHARED ${sources} ${headers} G__FCCAnalysesHiggs.cxx )
target_include_directories(FCCAnalysesHiggs  PUBLIC
                           ${CMAKE_SOURCE_DIR}/analyzers
	                         ${FCCANALYSES_INCLUDE_PATH}
                           ${FASTJET_INCLUDE_DIR}
)
target_link_libraries(FCCAnalysesHiggs ROOT::Physics 
                      ROOT::MathCore 
                      ROOT::ROOTVecOps 
                      ROOT::ROOTDataFrame 
                      EDM4HEP::edm4hep 
                      EDM4HEP::edm4hepDict 
                      podio::podio
                      ${FASTJET_LIBRARY} ${FASTJET_LIBRARY_DIRS}/libfastjetplugins.so)

set_target_properties(FCCAnalysesHiggs PROPERTIES
  PUBLIC_HEADER "${headers}")

install(TARGETS FCCAnalysesHiggs
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
    LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
    PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/FCCAnalysesHiggs"
    COMPONENT dev
    )

install(FILES
  "${PROJECT_BINARY_DIR}/analyzers/libFCCAnalysesHiggs.rootmap"
    DESTINATION "${INSTALL_LIB_DIR}" COMPONENT dev)

if (${ROOT_VERSION} GREATER 6)
    install(FILES
          "${PROJECT_BINARY_DIR}/analyzers/libFCCAnalysesHiggs_rdict.pcm"
                DESTINATION "${INSTALL_LIB_DIR}" COMPONENT dev)
    endif()
