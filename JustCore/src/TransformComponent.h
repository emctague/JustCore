// TransformComponent - 
// 
// Copyright (c) 2020 Ethan McTague
#pragma once

#include <JustLayers/ECS.h>
#include <util/Vector.h>

class TransformComponent : public jl::Component {
public:
    inline TransformComponent(Vec3 position, Vec3 rotation, Vec3 scale) : position(position), rotation(rotation), scale(scale) {}
    inline explicit TransformComponent(Vec3 position) : position(position) {}
    inline TransformComponent() = default;
    inline TransformComponent(float x, float y, float z) : position({ x, y, z }) {}
    inline TransformComponent(float x, float y) : position({ x, y, 0 }) {}

    Vec3 position, rotation, scale;

};


