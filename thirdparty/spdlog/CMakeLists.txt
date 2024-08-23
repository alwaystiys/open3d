cmake_minimum_required(VERSION 3.5)
project(spdlog)


#依赖开源的interface库spdlog，添加一个interface类型的库目标
add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE include "${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include")

#spdlog依赖的线程库
# find_package(Threads REQUIRED)

# target_link_libraries(spdlog PUBLIC Threads::Threads)

# https://www.jianshu.com/p/55be9d4fc033

