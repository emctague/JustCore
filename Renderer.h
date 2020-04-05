#pragma once

#include <JustLayers/Taskmaster.h>
#include <SFML/Graphics.hpp>
#include "UITransformComponent.h"
#include <iostream>

class Renderer : public jl::ITask {

    sf::RenderWindow window;

public:

    explicit Renderer(jl::Taskmaster *tm);

    bool updateTask(jl::Taskmaster *taskmaster) override;

    template<typename T>
    void drawHUD(T *drawable, UITransformComponent *uiTransform) {
        drawable->setScale(uiTransform->scale);
        auto bounds = drawable->getGlobalBounds();

        drawable->setPosition(uiTransform->onScreen(sf::Vector2f(window.getSize()), sf::Vector2f(bounds.width, bounds.height)));
        window.draw(*drawable);
    }
};


