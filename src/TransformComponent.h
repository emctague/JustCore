// TransformComponent - 
// 
// Copyright (c) 2020 Ethan McTague
#pragma once

#include <SFML/Graphics.hpp>
#include <JustLayers/ECS.h>

class TransformComponent : public jl::Component {
public:
    inline TransformComponent(sf::Vector3f position, sf::Vector3f rotation, sf::Vector3f scale) : position(position), rotation(rotation), scale(scale) {}
    inline explicit TransformComponent(sf::Vector3f position) : position(position) {}
    inline TransformComponent() = default;
    inline TransformComponent(float x, float y, float z) : position(x, y, z) {}
    inline TransformComponent(float x, float y) : position(x, y, 0) {}

    sf::Vector3f position, rotation, scale;

    inline sf::Vector2f position2D() { return sf::Vector2f(position.x, position.y); }
};


