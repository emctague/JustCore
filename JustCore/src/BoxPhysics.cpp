// BoxPhysics - 
// 
// Copyright (c) 2020 Ethan McTague
//#include <iostream>
//#include "BoxPhysics.h"
//
//BoxPhysics::BoxPhysics(jl::Taskmaster *taskmaster) : gravity(0.0f, 32.0f), world(std::make_shared<b2World>(gravity)) {
//    taskmaster->addTask(jl::IndirectTask::make(this));
//}
//
//bool BoxPhysics::updateTask(jl::Taskmaster *taskmaster, float delta) {
//    world->Step(delta, 8, 4);
//    return true;
//}
//
//BoxBody *BoxPhysics::makeBody(b2PolygonShape shape, sf::Vector2f position, float rotation, b2BodyType bodyType) {
//    b2BodyDef bodyDef;
//    bodyDef.type = bodyType;
//    bodyDef.position = b2Vec2(position.x, position.y);
//    bodyDef.angle = rotation;
//    bodyDef.linearDamping = 1.0f;
//
//    b2FixtureDef fixDef;
//    fixDef.shape = &shape;
//    fixDef.density = 1.0f;
//    fixDef.friction = 0.0f;
//    fixDef.restitution = 0;
//
//    b2Body *body = world->CreateBody(&bodyDef);
//    body->CreateFixture(&fixDef);
//
//    return new BoxBody(body, this);
//}
//
//BoxBody::BoxBody(b2Body *body, BoxPhysics *bp) : body(body), world(bp->world) {
//
//}
//
//BoxBody::~BoxBody() {
//    body->GetWorld()->DestroyBody(body);
//}
//
//bool BoxTransformSystem::updateTask(jl::Taskmaster *taskmaster, float delta) {
//
//    for (auto& entity : entities) {
//        auto body = std::get<std::shared_ptr<BoxBody>>(entity.second);
//        auto transform = std::get<std::shared_ptr<UITransformComponent>>(entity.second);
//
//        auto bodyPos = body->body->GetPosition();
//
//        transform->position = sf::Vector2f(bodyPos.x * 100.0f, bodyPos.y * 100.0f);
//    }
//
//    return true;
//}
//
//BoxTransformSystem::BoxTransformSystem(jl::ECS *ecs, jl::Taskmaster *tm) : System(ecs, tm) {
//
//}
