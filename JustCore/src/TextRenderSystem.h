// TextRenderSystem -
// 
// Copyright (c) 2020 Ethan McTague
#pragma once
/*
#include <JustLayers/System.h>
#include <SFML/Graphics.hpp>
#include <utility>
#include "TransformComponent.h"
#include "UITransformComponent.h"
#include "Renderer.h"

class TextComponent : public jl::Component {
public:
    inline TextComponent(std::string text) : text(std::move(text)) {}
    std::string text;
};

class TextRenderSystem : public jl::System<TextRenderSystem, TextComponent, UITransformComponent> {

    sf::Font debugFont;
    sf::Text text;
    Renderer *renderer;

public:

    TextRenderSystem(jl::ECS *ecs, jl::Taskmaster *tm, Renderer *renderer);
    bool updateTask(jl::Taskmaster *taskmaster, float delta) override;

};
*/