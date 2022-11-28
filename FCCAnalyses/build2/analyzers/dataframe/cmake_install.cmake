# Install script for directory: /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/analyzers/dataframe/libFCCAnalyses.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so"
         OLD_RPATH "/cvmfs/sw.hsf.org/spackages5/root/6.26.00/x86_64-centos7-gcc11.2.0-opt/jx56q/lib:/cvmfs/sw.hsf.org/spackages5/edm4hep/0.4.1/x86_64-centos7-gcc11.2.0-opt/22m2i/lib64:/cvmfs/sw.hsf.org/spackages5/fastjet/3.3.4/x86_64-centos7-gcc11.2.0-opt/lssz5/lib:/cvmfs/sw.hsf.org/spackages5/acts/17.1.0/x86_64-centos7-gcc11.2.0-opt/xbqry/lib64:/cvmfs/sw.hsf.org/spackages5/py-awkward/1.4.0/x86_64-centos7-gcc11.2.0-opt/ee337/lib/python3.9/site-packages/awkward:/cvmfs/sw.hsf.org/spackages5/dd4hep/1.20.1/x86_64-centos7-gcc11.2.0-opt/bvq6v/lib:/cvmfs/sw.hsf.org/spackages5/vdt/0.4.3/x86_64-centos7-gcc11.2.0-opt/vtti3/lib:/cvmfs/sw.hsf.org/spackages5/podio/0.14.1/x86_64-centos7-gcc11.2.0-opt/apzae/lib64:/cvmfs/sw.hsf.org/spackages5/xerces-c/3.2.3/x86_64-centos7-gcc11.2.0-opt/a4ijt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sw.hsf.org/contrib/binutils/2.37/x86_64-centos7-gcc4.8.5-opt/e44ldsiooccrs2h2eylg3br24u74dj23/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libFCCAnalyses.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/FCCAnalyses" TYPE FILE FILES
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/Algorithms.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/CaloNtupleizer.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/ExternalRecombiner.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/JetClustering.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/JetClusteringUtils.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/JetTaggingUtils.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/LinkDef.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/MCParticle.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/ReconstructedParticle.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/ReconstructedParticle2MC.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/ReconstructedParticle2Track.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/Smearing.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/ValenciaPlugin.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/VertexFinderActs.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/VertexFitterActs.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/VertexFitterSimple.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/VertexingUtils.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/awkwardtest.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/dummyLoader.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/myFinalSel.h"
    "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/analyzers/dataframe/myUtils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/analyzers/dataframe/libFCCAnalyses.rootmap")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/build/analyzers/dataframe/libFCCAnalyses_rdict.pcm")
endif()

