cmake_minimum_required(VERSION 3.17)
project(factory_pattern)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE objectSpawner imgui::imgui)
