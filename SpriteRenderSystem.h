#pragma once

#include <JustLayers/System.h>
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class SpriteComponent : public jl::Component {
public:
    inline SpriteComponent(std::shared_ptr<sf::Texture> texture) : texture(std::move(texture)) {}
    std::shared_ptr<sf::Texture> texture;
};

class SpriteRenderSystem : public jl::System<SpriteRenderSystem, SpriteComponent, UITransformComponent> {

    sf::Sprite sprite;
    Renderer *renderer;

public:

    SpriteRenderSystem(jl::ECS *ecs, jl::Taskmaster *tm, Renderer *renderer);
    bool updateTask(jl::Taskmaster *taskmaster) override;

};
