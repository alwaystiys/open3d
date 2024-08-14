cmake_minimum_required(VERSION 3.5)

project(imgui)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME})

target_link_libraries(imgui PUBLIC glfw glad)