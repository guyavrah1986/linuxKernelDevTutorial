# =====================================================================================================================================
# general project settings
# ======================================================================================================================================
cmake_minimum_required(VERSION 3.9)

project(infra)

message(STATUS "processing CMakeLists of project:${CMAKE_PROJECT_NAME} within folder:${CMAKE_CURRENT_LIST_DIR}")

# enable c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================================================================================================================================
# include directories
# ======================================================================================================================================
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../globalIncludeDir)

# in order to be able to unit-test the provate function of the classes

# ======================================================================================================================================
# group all source files of the executable
# ======================================================================================================================================
file(GLOB_RECURSE INFRA_SRC "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
			    "${CMAKE_CURRENT_LIST_DIR}/*.h")

# ======================================================================================================================================
# add relevant sub directories -- invoke their CMakeLists.txt files
# ======================================================================================================================================

# std thread RAII wrapper library (class)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/stdThreadRaiiWrapper/ ${CMAKE_CURRENT_LIST_DIR}/../../build/infra/stdThreadRaiiWrapper)

# secure connection library (class)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/secureConnectionHandler/ ${CMAKE_CURRENT_LIST_DIR}/../../build/infra/secureConnectionHandler)

# ======================================================================================================================================
# create the library 
# ======================================================================================================================================
add_library(infraLib SHARED ${INFRA_SRC})

   
# ======================================================================================================================================
# link the library with all other relevant libraries
# ======================================================================================================================================
target_link_libraries(infraLib stdThreadRaiiWrapperLib secureConnectionHandlerLib glog)
