#include "UITransformComponent.h"

sf::Vector2f UITransformComponent::onScreen(sf::Vector2f screenSize, sf::Vector2f objSize) {
    return sf::Vector2f(
            onAxis(position.x, objSize.x, horizontal, screenSize.x),
            onAxis(position.y, objSize.y, vertical, screenSize.y)
    );
}

