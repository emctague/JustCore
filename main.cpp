#include <iostream>
#include <JustLayers/ECS.h>
#include <JustLayers/Taskmaster.h>
#include <JustLayers/ResourceManager.h>
#include "TextRenderSystem.h"
#include "SpriteRenderSystem.h"

int main() {
    jl::ECS ecs;
    jl::Taskmaster taskmaster;

    jl::ResourceManager<sf::Texture, std::string> textureManager([](std::string path) {
        auto tex = std::make_unique<sf::Texture>();
        tex->loadFromFile(path);
        return tex;
    });

    Renderer renderer(&taskmaster);
    TextRenderSystem trs(&ecs, &taskmaster, &renderer);
    SpriteRenderSystem srs(&ecs, &taskmaster, &renderer);

    ecs.addEntity(new jl::Entity{
            new TextComponent("Hello!"),
            new UITransformComponent({ 20.0f, 20.0f }, Begin, Begin)
    });


    ecs.addEntity(new jl::Entity{
            new TextComponent("I am an entity with a TextComponent!"),
            new UITransformComponent({ 20.0f, 20.0f }, End, End)
    });

    ecs.addEntity(new jl::Entity{
            new SpriteComponent(textureManager.get("../shrek.png")),
            new UITransformComponent({ 0.0f, 0.0f }, Center, Center,
                                     { 0.2f, 0.2f })
    });

    taskmaster.start();
    return 0;
}

