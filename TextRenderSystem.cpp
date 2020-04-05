// TextRenderSystem -
// 
// Copyright (c) 2020 Ethan McTague
#include <iostream>
#include "TextRenderSystem.h"
#include "UITransformComponent.h"

TextRenderSystem::TextRenderSystem(jl::ECS *ecs, jl::Taskmaster *tm, Renderer *renderer) :
    System(ecs, tm),
    renderer(renderer) {

    debugFont.loadFromFile("../Source_Code_Pro/SourceCodePro-Regular.ttf");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setFont(debugFont);
}

bool TextRenderSystem::updateTask(jl::Taskmaster *taskmaster) {

    for (auto& entity : entities) {
        auto txt = std::get<std::shared_ptr<TextComponent>>(entity.second);
        auto transform = std::get<std::shared_ptr<UITransformComponent>>(entity.second);

        text.setString(txt->text);
        renderer->drawHUD(&text, transform.get());
    }

    return true;
}
