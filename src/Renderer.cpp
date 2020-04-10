#include "Renderer.h"

bool Renderer::updateTask(jl::Taskmaster *taskmaster, float delta) {

    /// Handle window events
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            taskmaster->stop();
            window.close();
        } else if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
    }

    window.display();
    window.clear();

    return true;
}

Renderer::Renderer(jl::Taskmaster *tm)
    : window(sf::VideoMode(1280, 720), "JustCore Basic Renderer") {
    window.setVerticalSyncEnabled(true);

    tm->addTask(jl::IndirectTask::make(this));
}
