// BoxPhysics - 
// 
// Copyright (c) 2020 Ethan McTague
#pragma once
//
//#include <box2d/box2d.h>
//#include <JustLayers/Taskmaster.h>
//#include <JustLayers/ECS.h>
//#include <JustLayers/System.h>
//#include <SFML/System.hpp>
//#include "UITransformComponent.h"
//
//
//class BoxPhysics;
//
//class BoxBody : public jl::Component {
//public:
//
//    b2Body *body;
//    std::shared_ptr<b2World> world;
//
//    BoxBody(b2Body *body, BoxPhysics *bp);
//    ~BoxBody() override;
//};
//
//class BoxPhysics : public jl::ITask {
//    b2Vec2 gravity;
//
//    friend class BoxBody;
//    std::shared_ptr<b2World> world;
//
//
//public:
//    BoxPhysics(jl::Taskmaster *taskmaster);
//
//    bool updateTask(jl::Taskmaster *taskmaster, float delta) override;
//
//    BoxBody *makeBody(b2PolygonShape shape, sf::Vector2f position, float rotation = 0.0f, b2BodyType bodyType = b2BodyType::b2_dynamicBody);
//    static inline b2PolygonShape rect(float width, float height) {
//        b2PolygonShape shape;
//        shape.SetAsBox(width, height);
//        return shape;
//    }
//};
//
//
//class BoxTransformSystem : public jl::System<BoxTransformSystem, BoxBody, UITransformComponent> {
//public:
//    BoxTransformSystem(jl::ECS *ecs, jl::Taskmaster *tm);
//    bool updateTask(jl::Taskmaster *taskmaster, float delta) override;
//
//};