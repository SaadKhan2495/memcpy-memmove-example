cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

#Exception Handling
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/memmove-memcopy)

project(memcpy)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/memcpy-example.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

project(memmove)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/memmove-example.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})