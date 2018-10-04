# ======================================================================================================================================
# general project settings
# ======================================================================================================================================
cmake_minimum_required(VERSION 3.9.6)

project(unitTests)

message(STATUS "Processing CMakeLists.txt file in folder:${CMAKE_CURRENT_LIST_DIR}")

# ======================================================================================================================================
# GTest realted settings
# ======================================================================================================================================

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest-release-1.8.0)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# ======================================================================================================================================
# include directories
# ======================================================================================================================================

include_directories(${CMAKE_CURRENT_LIST_DIR}/../globalIncludeDir 
		    ${CMAKE_CURRENT_LIST_DIR}/../src/handlers
		    ${CMAKE_CURRENT_LIST_DIR}/../src/handlers
		    ${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests
	            ${CMAKE_CURRENT_LIST_DIR})

# ======================================================================================================================================
# group all source files of the executable
# ======================================================================================================================================

# ProcHnadler unit tests sources 
file(GLOB_RECURSE PROC_HANDLER_UNIT_TESTS_SRC
    "${CMAKE_CURRENT_LIST_DIR}/procHandlerUnitTests/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/procHandlerUnitTests/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.h"
    "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c")

# ProcDetaile unit tests sources 
file(GLOB_RECURSE PROC_DETAILES_UNIT_TESTS_SRC
	"${CMAKE_CURRENT_LIST_DIR}/procDetailesUnitTests/*.h"
	"${CMAKE_CURRENT_LIST_DIR}/procDetailesUnitTests/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.h"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c")

# ThreadWrapper unit tests sources 
file(GLOB_RECURSE THREAD_WRAPPER_UNIT_TESTS_SRC
	"${CMAKE_CURRENT_LIST_DIR}/infraUnitTests/threadWrapperUnitTests/*.h"
	"${CMAKE_CURRENT_LIST_DIR}/infraUnitTests/threadWrapperUnitTests/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.h"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c")

# bioOperationUnitTests unit tests sources 
file(GLOB_RECURSE BIO_OPERATION_UNIT_TESTS_SRC
	"${CMAKE_CURRENT_LIST_DIR}/infraUnitTests/bioOperationUnitTests/*.h"
	"${CMAKE_CURRENT_LIST_DIR}/infraUnitTests/bioOperationUnitTests/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.h"
        "${CMAKE_CURRENT_LIST_DIR}/mallocAndFreeWrappersForUnitTests/mallocAndFreeWrappers.c")


# ======================================================================================================================================
# Create dependencies libraries
# ======================================================================================================================================


# ======================================================================================================================================
# create the unit tests executables
# ======================================================================================================================================

add_executable(procHandlerUnitTestsExe ${PROC_HANDLER_UNIT_TESTS_SRC})

add_executable(procDetailesUnitTestsExe ${PROC_DETAILES_UNIT_TESTS_SRC})

add_executable(threadWrapperUnitTestsExe ${THREAD_WRAPPER_UNIT_TESTS_SRC})

add_executable(bioOperationUnitTestsExe ${BIO_OPERATION_UNIT_TESTS_SRC})

# ======================================================================================================================================
# link the each executable with all relevant libraries
# ======================================================================================================================================

target_link_libraries(procHandlerUnitTestsExe gtest gtest_main handlersLib utilsLib)

target_link_libraries(procDetailesUnitTestsExe gtest gtest_main handlersLib utilsLib)

target_link_libraries(threadWrapperUnitTestsExe gtest gtest_main stdThreadRaiiWrapperLib utilsLib)

target_link_libraries(bioOperationUnitTestsExe gtest gtest_main utilsLib)

# ======================================================================================================================================
# GTest realted settings for the unit test exe
# ======================================================================================================================================

add_test(procHandlerUnitTestsExe procHandlerUnitTestsExe)

add_test(procDetailesUnitTestsExe procDetailesUnitTestsExe)

add_test(threadWrapperUnitTestsExe threadWrapperUnitTestsExe)

add_test(bioOperationUnitTestsExe bioOperationUnitTestsExe)


