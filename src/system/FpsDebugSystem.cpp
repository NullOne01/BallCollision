#include <SFML/System/String.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "FpsDebugSystem.h"

FpsDebugSystem::FpsDebugSystem(sf::RenderWindow *window, World *world) : SystemBase(world), window_(window) {
}

void FpsDebugSystem::update(float deltaTime) {
    fpsCounter_.push(1.0f / deltaTime);
    drawFps(fpsCounter_.getAverage());
}

void FpsDebugSystem::drawFps(float fps) {
    char c[32];
    snprintf(c, 32, "FPS: %f", fps);
    std::string string(c);
    sf::String str(c);
    window_->setTitle(str);
}

