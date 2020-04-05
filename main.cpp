#include <iostream>
#include <JustLayers/ECS.h>
#include <JustLayers/Taskmaster.h>
#include <JustLayers/ResourceManager.h>
#include "TextRenderSystem.h"
#include "SpriteRenderSystem.h"

class TestPhysicsComponent : public jl::Component {
public:

    explicit TestPhysicsComponent(sf::Vector2f size, bool hasGravity = false) : hitboxSize(size), hasGravity(hasGravity) {}
    sf::Vector2f velocity;
    sf::Vector2f hitboxSize;
    bool hasGravity;
};

class PlayerComponent : public jl::Component {
public:
    PlayerComponent() = default;
};

class TestPhysicsSystem : public jl::System<TestPhysicsSystem, TestPhysicsComponent, UITransformComponent> {
public:
    TestPhysicsSystem(jl::ECS *ecs, jl::Taskmaster *tm) : System(ecs, tm) {}

    bool updateTask(jl::Taskmaster *taskmaster, float delta) override {

        if (delta > 0.1f) delta = 0.1f;

        for (auto& entity : entities) {
            auto phys = std::get<std::shared_ptr<TestPhysicsComponent>>(entity.second);
            auto pos = std::get<std::shared_ptr<UITransformComponent>>(entity.second);
            if (phys->hasGravity) { phys->velocity.y += 980.f * delta; }

            auto newPos = pos->position + phys->velocity * delta;

            for (auto& other : entities) {
                if (other.first == entity.first) continue;
                auto otherPhys = std::get<std::shared_ptr<TestPhysicsComponent>>(other.second);
                auto otherPos = std::get<std::shared_ptr<UITransformComponent>>(other.second);


#define EITHER_INRANGE(AMIN, AADD, BMIN, BADD) (AMIN <= BMIN + BADD && AMIN + AADD >= BMIN)

                if (EITHER_INRANGE(otherPos->position.x, otherPhys->hitboxSize.x, newPos.x, phys->hitboxSize.x)
                    && EITHER_INRANGE(otherPos->position.y, otherPhys->hitboxSize.y, pos->position.y, phys->hitboxSize.y)) {
                    phys->velocity.x = 0;
                }

                if (EITHER_INRANGE(otherPos->position.x, otherPhys->hitboxSize.x, pos->position.x, phys->hitboxSize.x)
                    && EITHER_INRANGE(otherPos->position.y, otherPhys->hitboxSize.y, newPos.y, phys->hitboxSize.y)) {
                    phys->velocity.y = 0;
                }

            }

            pos->position = pos->position + phys->velocity * delta;

        }
        return true;
    }
};

class PlayerSystem : public jl::System<PlayerSystem, TestPhysicsComponent, PlayerComponent> {

    bool wasPressed = false;

public:
    PlayerSystem(jl::ECS *ecs, jl::Taskmaster *tm) : System(ecs, tm) {}

    bool updateTask(jl::Taskmaster *taskmaster, float delta) override {

        auto isPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        auto isNewPress = !wasPressed && isPressed;
        wasPressed = isPressed;


        for (auto& entity : entities) {
            auto phys = std::get<std::shared_ptr<TestPhysicsComponent>>(entity.second);

            if (isNewPress) {
                phys->velocity.y -= 600.0f;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                phys->velocity.x += 500.0f * delta;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                phys->velocity.x -= 500.0f * delta;
        }
        return true;
    }
};


class PhysDebugSystem : public jl::System<PlayerSystem, TestPhysicsComponent, UITransformComponent> {

    bool wasPressed = false;

    Renderer *renderer;

public:
    PhysDebugSystem(jl::ECS *ecs, jl::Taskmaster *tm, Renderer *renderer) : System(ecs, tm), renderer(renderer) {}

    bool updateTask(jl::Taskmaster *taskmaster, float delta) override {

        sf::RectangleShape rect;
        rect.setFillColor(sf::Color(255, 0, 0, 100));


        for (auto& entity : entities) {
            auto phys = std::get<std::shared_ptr<TestPhysicsComponent>>(entity.second);
            auto pos =  std::get<std::shared_ptr<UITransformComponent>>(entity.second);

            rect.setSize(phys->hitboxSize);
            renderer->drawHUD(&rect, pos.get());

        }
        return true;
    }
};




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
    TestPhysicsSystem tps(&ecs, &taskmaster);
    PlayerSystem ps(&ecs, &taskmaster);
    //PhysDebugSystem pds(&ecs, &taskmaster, &renderer);

    ecs.addEntity(new jl::Entity {
        new PlayerComponent(),
        new TestPhysicsComponent({ 42.0f, 30.0f }, true),
        new UITransformComponent({ 200.0f, 200.0f }, Begin, Begin),
        new TextComponent("ME")
    });

    ecs.addEntity(new jl::Entity {
        new TestPhysicsComponent({ 290.0f, 30.0f }),
        new UITransformComponent({ 200.0f, 240.0f }, Begin, Begin),
        new TextComponent("I AM A FLOOR")
    });

    taskmaster.start();
    return 0;
}

