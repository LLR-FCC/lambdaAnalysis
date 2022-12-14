
cmake_minimum_required(VERSION 2.8)

project(FCCAnalysesFlavour CXX)

find_package(ROOT COMPONENTS ROOTDataFrame)
include(${ROOT_USE_FILE})

find_package(EDM4HEP)
find_package(podio)


# Define basic build settings
# Use GNU-style hierarchy for installing build products
include(GNUInstallDirs)


set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
find_package(Vdt)
find_package(FastJet)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")

add_subdirectory(analyzers)

set(FCCANALYSES_INCLUDE_PATH "FCCAnalysesIncludePath" CACHE PATH "Description")
message(STATUS "FCCAnalysesIncludePath ${FCCANALYSES_INCLUDE_PATH}")
