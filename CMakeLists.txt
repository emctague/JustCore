cmake_minimum_required(VERSION 3.15)
project(JustCore)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JustLayers)

find_package(SFML COMPONENTS graphics REQUIRED)
add_executable(JustCore main.cpp RenderSystem.cpp RenderSystem.h TransformComponent.cpp TransformComponent.h)
target_link_libraries(JustCore JustLayers sfml-graphics)