#include <iostream>
#include <JustLayers/ECS.h>
#include <JustLayers/Taskmaster.h>
#include "RenderSystem.h"

int main() {
    jl::ECS ecs;
    jl::Taskmaster taskmaster;
    RenderSystem rs(&ecs, &taskmaster);

    ecs.addEntity((new jl::Entity())
                          ->addComponent(new TextComponent("Hello!"))
                          ->addComponent(new TransformComponent(20.0f, 20.0f)));

    ecs.addEntity((new jl::Entity())
                          ->addComponent(new TextComponent("I am an entity with a TextComponent!"))
                          ->addComponent(new TransformComponent(200.0f, 200.0f)));

    taskmaster.start();
    return 0;
}

