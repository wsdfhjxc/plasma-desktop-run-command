cmake_minimum_required(VERSION 3.0)
project(plasma_containmentactions_runcommand)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

find_package(ECM REQUIRED NO_MODULE)

set(CMAKE_AUTOUIC ON)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

find_package(Qt5 5.3.0 REQUIRED COMPONENTS Widgets)
find_package(KF5 5.0.0 REQUIRED COMPONENTS Plasma)

set(sources src/RunCommand.cpp src/Config.ui)

add_library(plasma_containmentactions_runcommand MODULE ${sources})
kcoreaddons_desktop_to_json(plasma_containmentactions_runcommand src/metadata.desktop)
target_link_libraries(plasma_containmentactions_runcommand Qt5::Widgets KF5::Plasma)

install(TARGETS plasma_containmentactions_runcommand DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/containmentactions)
