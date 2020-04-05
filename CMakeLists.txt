cmake_minimum_required(VERSION 3.15)
project(JustCore)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JustLayers)

find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
add_executable(JustCore main.cpp TextRenderSystem.cpp TextRenderSystem.h TransformComponent.cpp TransformComponent.h UITransformComponent.cpp UITransformComponent.h Renderer.cpp Renderer.h SpriteRenderSystem.cpp SpriteRenderSystem.h)
target_link_libraries(JustCore JustLayers sfml-graphics)