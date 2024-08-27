cmake_minimum_required(VERSION 3.5)
project(open3d)

# add c++ standard
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/glfw-3.4)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/imgui-docking)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/spdlog)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCES})
# add_executable(${PROJECT_NAME} src/main.cpp)


# add include directory
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw glad imgui glm spdlog) # glad stb_image stb_truetype imgui)
 

#spdlog依赖的线程库
# find_package(Threads REQUIRED) 