#pragma once

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;

    Vec2 xy() { return { x, y }; }
    Vec2 xz() { return { x, z }; }
    Vec2 yz() { return { y, z }; }
};
