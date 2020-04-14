#include <iostream>
#include <JustLayers/ECS.h>
#include <JustLayers/Taskmaster.h>
#include <JustLayers/ResourceManager.h>
#include "TextRenderSystem.h"
#include "SpriteRenderSystem.h"
#include "BoxPhysics.h"

/*
class PlayerComponent : public jl::Component {
public:
    PlayerComponent() = default;
};

class PlayerSystem : public jl::System<PlayerSystem, BoxBody, PlayerComponent> {

    bool wasPressed = false;

public:
    PlayerSystem(jl::ECS *ecs, jl::Taskmaster *tm) : System(ecs, tm) {}

    bool updateTask(jl::Taskmaster *taskmaster, float delta) override {

        auto isPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        auto isNewPress = !wasPressed && isPressed;
        wasPressed = isPressed;


        for (auto& entity : entities) {
            auto phys = std::get<std::shared_ptr<BoxBody>>(entity.second);


            if (isNewPress)
                phys->body->SetLinearVelocity(b2Vec2(phys->body->GetLinearVelocity().x, -20.0f));


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                phys->body->ApplyForceToCenter(b2Vec2(10.0f, 0.0f), true);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                phys->body->ApplyForceToCenter(b2Vec2(-10.0f, 0.0f), true);
        }
        return true;
    }
};

*/
void game() {
    jl::ECS ecs;
    jl::Taskmaster taskmaster;
//
//    jl::ResourceManager<sf::Texture, std::string> textureManager([](std::string path) {
//        auto tex = std::make_unique<sf::Texture>();
//        tex->loadFromFile(path);
//        return tex;
//    });
//
//    Renderer renderer(&taskmaster);
//    BoxPhysics bs(&taskmaster);
//
//    TextRenderSystem trs(&ecs, &taskmaster, &renderer);
//    SpriteRenderSystem srs(&ecs, &taskmaster, &renderer);
//    PlayerSystem ps(&ecs, &taskmaster);
//    BoxTransformSystem bt(&ecs, &taskmaster);
//    //PhysDebugSystem pds(&ecs, &taskmaster, &renderer);
//
//    ecs.addEntity(new jl::Entity {
//            new PlayerComponent(),
//            bs.makeBody(BoxPhysics::rect(42.0f / 100.0f, 30.0f / 100.0f), { 200.0f / 100.0f, 200.0f / 100.0f }, 0.0f, b2BodyType::b2_dynamicBody),
//            new UITransformComponent({ 200.0f, 200.0f }, Begin, Begin),
//            new TextComponent("ME")
//    });
//
//    ecs.addEntity(new jl::Entity {
//            bs.makeBody(BoxPhysics::rect(290.0f / 100.0f, 30.0f / 100.0f), { 200.0f / 100.0f, 240.0f / 100.0f }, 0.0f, b2BodyType::b2_staticBody),
//            new UITransformComponent({ 200.0f, 240.0f }, Begin, Begin),
//            new TextComponent("I AM A FLOOR")
//    });
//
//    taskmaster.start();
}


//
//#ifdef WINDOWS_UWP
//
//[Platform::MTAThread]
//int main(Platform::Array<Platform::String^>^)
//{
//    Platform::Agile<Windows::UI::Core::CoreWindow> window;
//
//    game();
//
//    return 0;
//}
//
//#else
//
//int main() {
//    game();
//    return 0;
//}
//
//#endif
