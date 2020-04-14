
#find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
#find_package(glad REQUIRED)
add_library(JustCore game.cpp TextRenderSystem.cpp TextRenderSystem.h TransformComponent.cpp TransformComponent.h SpriteRenderSystem.cpp SpriteRenderSystem.h BoxPhysics.cpp BoxPhysics.h graphics/Renderer.cpp graphics/Renderer.h UWPMain.cpp util/Vector.cpp util/Vector.h)
target_link_libraries(JustCore JustLayers box2d)
target_include_directories(JustCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
