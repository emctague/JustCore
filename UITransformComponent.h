#pragma once


#include <JustLayers/ECS.h>
#include <SFML/System.hpp>

enum UISnap {
    Begin,
    Center,
    End
};

class UITransformComponent : public jl::Component {

    inline float onAxis(float pos, float size, UISnap snap, float max) {
        switch (snap) {
            case Begin:
                return pos;
            case End:
                return max - size - pos;
            case Center:
                return max / 2 + pos - size / 2;
        }
    }

public:


    inline UITransformComponent(sf::Vector2f position, UISnap vertical, UISnap horizontal, sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f)) :
        position(position), vertical(vertical), horizontal(horizontal), scale(scale) {}

    sf::Vector2f position;
    sf::Vector2f scale;

    UISnap vertical, horizontal;

    sf::Vector2f onScreen(sf::Vector2f screenSize, sf::Vector2f objSize);
};


