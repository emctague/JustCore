// Renderer - 
// 
// Copyright (c) 2020 Ethan McTague
#include "Renderer.h"

Renderer::Renderer(GLADloadproc glProcFunc) {
    gladLoadGLLoader(glProcFunc);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
}
