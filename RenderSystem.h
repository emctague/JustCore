// RenderSystem - 
// 
// Copyright (c) 2020 Ethan McTague
#pragma once

#include <JustLayers/System.h>
#include <SFML/Graphics.hpp>
#include <utility>
#include "TransformComponent.h"

class TextComponent : public jl::Component {
public:
    inline TextComponent(std::string text) : text(std::move(text)) {}
    std::string text;
};

class RenderSystem : public jl::System<RenderSystem, TextComponent, TransformComponent> {

    sf::RenderWindow window;
    sf::Font debugFont;
    sf::Text text;

public:

    RenderSystem(jl::ECS *ecs, jl::Taskmaster *tm);
    bool updateTask(jl::Taskmaster *taskmaster) override;

};
