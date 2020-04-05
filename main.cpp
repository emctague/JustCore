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

    ecs.addEntity((new jl::Entity())
                          ->addComponent(new TextComponent("Hello!"))
                          ->addComponent(
                                  new UITransformComponent(sf::Vector2f(20.0f, 20.0f), UISnap::Begin, UISnap::Begin)));

    ecs.addEntity((new jl::Entity())
                          ->addComponent(new TextComponent("I am an entity with a TextComponent!"))
                          ->addComponent(
                                  new UITransformComponent(sf::Vector2f(20.0f, 20.0f), UISnap::End, UISnap::End)));

    ecs.addEntity((new jl::Entity())
                          ->addComponent(new SpriteComponent(textureManager.get("../shrek.png")))
                          ->addComponent(
                                  new UITransformComponent(sf::Vector2f(0.0f, 0.0f), UISnap::Center, UISnap::Center, sf::Vector2f(0.2f, 0.2f))));

    taskmaster.start();
    return 0;
}

