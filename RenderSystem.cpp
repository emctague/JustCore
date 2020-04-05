// RenderSystem - 
// 
// Copyright (c) 2020 Ethan McTague
#include <iostream>
#include "RenderSystem.h"

RenderSystem::RenderSystem(jl::ECS *ecs, jl::Taskmaster *tm) :
    System(ecs, tm),
    window(sf::VideoMode(1920, 1080), "Title") {

    window.setVerticalSyncEnabled(true);

    debugFont.loadFromFile("../Source_Code_Pro/SourceCodePro-Regular.ttf");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setFont(debugFont);
}

bool RenderSystem::updateTask(jl::Taskmaster *taskmaster) {

    /// Handle window events
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            taskmaster->stop();
            window.close();
        }
    }

    window.clear();

    for (auto& entity : entities) {
        auto txt = std::get<std::shared_ptr<TextComponent>>(entity.second);
        auto transform = std::get<std::shared_ptr<TransformComponent>>(entity.second);

        text.setString(txt->text);
        text.setPosition(transform->position2D());

        window.draw(text);
    }

    window.display();

    return true;
}
