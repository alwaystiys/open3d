cmake_minimum_required(VERSION 3.5)
project(glad)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/gl.c)
target_include_directories(${PROJECT_NAME} PUBLIC include)