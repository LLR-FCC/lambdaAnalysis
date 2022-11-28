# Install script for directory: /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/__init__.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/common_defaults.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/doPlots.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/kinematics.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/runCombinatorics.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/runDataFrame.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/runDataFrameBatch.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/runDataFrameFinal.py;/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/setup.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config" TYPE FILE FILES
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/__init__.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/common_defaults.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/doPlots.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/kinematics.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/runCombinatorics.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/runDataFrame.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/runDataFrameBatch.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/runDataFrameFinal.py"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/setup.py"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config/doPlots.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/install/python/config" TYPE FILE PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ FILES "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/doPlots.py")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/analyzers/dataframe/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/FCCAnalyses/doxygen" TYPE DIRECTORY OPTIONAL FILES "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/doxygen")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
