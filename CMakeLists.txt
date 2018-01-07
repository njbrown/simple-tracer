cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(tracer)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Concurrent Svg)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/assimp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

option(ASSIMP_BUILD_ASSIMP_TOOLS                "" OFF)
option(ASSIMP_BUILD_TESTS                       "" OFF)
option(ASSIMP_NO_EXPORT                         "" ON)
option(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT    "" OFF)
option(ASSIMP_BUILD_OBJ_IMPORTER                "" ON)
option(ASSIMP_BUILD_FBX_IMPORTER                "" ON)
option(ASSIMP_BUILD_COLLADA_IMPORTER            "" ON)
option(ASSIMP_BUILD_ZLIB                        "" ON)

set_target_properties(assimp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



set(SRCS
	renderwindow.cpp)

set(HEADERS
	renderwindow.h
)

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SRCS} ${HEADERS})
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Core assimp)