cmake_minimum_required(VERSION 3.0)

# Dependencies
find_package(Qt5 CONFIG REQUIRED Core)

set(CMAKE_AUTOMOC ON)

# Sources
set(example_SRCS
    example.cpp
    )

# Building
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

add_definitions(-DEXAMPLE_JSON_PATH="${CMAKE_CURRENT_SOURCE_DIR}/example.json")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Woverloaded-virtual -std=c++11")
add_executable(example ${example_SRCS})

target_link_libraries(example Qt5::Core)
