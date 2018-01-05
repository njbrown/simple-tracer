project(tracer)

find_package(Qt5
	REQUIRED
	COMPONENTS Widgets Concurrent Svg)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/assimp)

set(SRCS
	renderwindow.cpp)

set(HEADERS
	renderwindow.h
)

add_executable(tracer main.cpp ${SRCS} ${HEADERS})