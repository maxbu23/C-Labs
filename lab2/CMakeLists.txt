cmake_minimum_required(VERSION 3.10)

project(project)

file (GLOB SOURCE src/*.cpp)

add_executable(project main.cpp ${SOURCE})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)