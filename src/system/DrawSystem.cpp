#include <SFML/Graphics/CircleShape.hpp>
#include "DrawSystem.h"

DrawSystem::DrawSystem(sf::RenderWindow *window, World *world) : SystemBase(world), window_(window) {
}

void DrawSystem::update(float deltaTime) {
    window_->clear();

    for (const auto &ball: world_->balls) {
        drawBall(ball);
    }
}

void DrawSystem::drawBall(const Ball &ball) {
    sf::CircleShape circleToDraw;
    circleToDraw.setRadius(ball.radius);
    circleToDraw.setFillColor(ball.color);
    circleToDraw.setPosition(ball.position.x, ball.position.y);
    window_->draw(circleToDraw);
}
