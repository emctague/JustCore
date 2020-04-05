#include "SpriteRenderSystem.h"

SpriteRenderSystem::SpriteRenderSystem(jl::ECS *ecs, jl::Taskmaster *tm, Renderer *renderer) : System(ecs, tm), renderer(renderer) {
}

bool SpriteRenderSystem::updateTask(jl::Taskmaster *taskmaster) {

    for (auto& entity : entities) {
        auto spr = std::get<std::shared_ptr<SpriteComponent>>(entity.second);
        auto transform = std::get<std::shared_ptr<UITransformComponent>>(entity.second);

        sprite.setTexture(*spr->texture, true);
        renderer->drawHUD(&sprite, transform.get());
    }

    return true;
}
