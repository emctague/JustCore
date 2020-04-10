
find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
add_executable(JustCore src/main.cpp src/TextRenderSystem.cpp src/TextRenderSystem.h src/TransformComponent.cpp src/TransformComponent.h src/UITransformComponent.cpp src/UITransformComponent.h src/Renderer.cpp src/Renderer.h src/SpriteRenderSystem.cpp src/SpriteRenderSystem.h src/BoxPhysics.cpp src/BoxPhysics.h)
target_link_libraries(JustCore JustLayers sfml-graphics box2d)
