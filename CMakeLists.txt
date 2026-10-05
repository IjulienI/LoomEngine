cmake_minimum_required(VERSION 4.3)
project(LoomEngine VERSION 0.1.0 LANGUAGES C CXX)

#----------------------------------------
# General options
#----------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pack exe and DLL in the same place, lib apart
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Binaries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Library)

option(LOOM_BUILD_EDITOR "Compiling Editor" ON)
option(LOOM_BUILD_SANDBOX "Compiling Sandbox project" ON)

# Build configurations
set(LOOM_BUILD_CONFIG "Development" CACHE STRING "Debug, Development, Shipping")
set_property(CACHE LOOM_BUILD_CONFIG PROPERTY STRINGS Debug Development Shipping)

if(NOT LOOM_BUILD_CONFIG MATCHES "^(Debug|Development|Shipping)$")
    message(FATAL_ERROR "LOOM_BUILD_CONFIG invalid : '${LOOM_BUILD_CONFIG}' (Debug, Development or Shipping)")
endif ()

include(cmake/LoomEngineHelpers.cmake)

#----------------------------------------
# Extern dependencies
#----------------------------------------
add_subdirectory(ThirdParty)

#----------------------------------------
# Engine modules
#----------------------------------------
add_subdirectory(Source/Core)
add_subdirectory(Source/Platform)
add_subdirectory(Source/Engine)
add_subdirectory(Source/Runtime)

if(LOOM_BUILD_SANDBOX)
    add_subdirectory(Sandbox)
endif ()

if(LOOM_BUILD_EDITOR)
    add_subdirectory(Source/Editor)
endif ()