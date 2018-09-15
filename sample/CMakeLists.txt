# =====================================================================================================================================
# general project settings
# ======================================================================================================================================
cmake_minimum_required(VERSION 3.9)

project("basicCyberProj")

#include(${CMAKE_CURRENT_LIST_DIR}/internalGlobalDefinitions/globalDefinitions.cmake)

message(STATUS "processing CMakeLists of project:${CMAKE_PROJECT_NAME} within folder:${CMAKE_CURRENT_LIST_DIR}")

# set the output directory for the executables, static and shared libraries are placed once finished to the build folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build")

# enable c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================================================================================================================================
# include directories
# ======================================================================================================================================
include_directories(${CMAKE_CURRENT_LIST_DIR}/globalIncludeDir ${CMAKE_CURRENT_LIST_DIR}/utils)

# ======================================================================================================================================
# group all source files of the executable
# ======================================================================================================================================
file(GLOB_RECURSE BCP_MAIN_EXE_SRC "${CMAKE_CURRENT_LIST_DIR}/main.cpp") 

# ======================================================================================================================================
# add relevant sub directories -- invoke their CMakeLists.txt files
# ======================================================================================================================================

# common - SHOULD BE BUILT FIRST !!
#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/common ${CMAKE_CURRENT_LIST_DIR}/build/common)

# utilities
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/utils/ ${CMAKE_CURRENT_LIST_DIR}/build/utils)

# handlers
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/handlers ${CMAKE_CURRENT_LIST_DIR}/build/src/handlers)

# unitTests
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unitTests ${CMAKE_CURRENT_LIST_DIR}/build/unitTests)


# ======================================================================================================================================
# create the main executable
# ======================================================================================================================================

add_executable(mainExe ${BCP_MAIN_EXE_SRC})
   
# ======================================================================================================================================
# link the main executable with all relevant libraries
# ======================================================================================================================================
                 
target_link_libraries(mainExe handlersLib utilsLib glog)
