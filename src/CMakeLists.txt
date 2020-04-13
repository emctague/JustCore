
find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
find_package(glad REQUIRED)
add_executable(JustCore main.cpp TextRenderSystem.cpp TextRenderSystem.h TransformComponent.cpp TransformComponent.h UITransformComponent.cpp UITransformComponent.h Renderer.cpp Renderer.h SpriteRenderSystem.cpp SpriteRenderSystem.h BoxPhysics.cpp BoxPhysics.h graphics/Renderer.cpp graphics/Renderer.h)
target_link_libraries(JustCore JustLayers sfml-graphics box2d glad::glad)
