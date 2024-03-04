#include <SFML/Graphics/RectangleShape.hpp>
#include "DrawCollisionSystem.h"
#include "../entity/World.h"

DrawCollisionSystem::DrawCollisionSystem(sf::RenderWindow *window, World *world) : SystemBase(world), window_(window) {

}

void DrawCollisionSystem::update(float deltaTime) {
    drawQuadtree();
}

void DrawCollisionSystem::drawQuadtree() {
    std::vector<sf::FloatRect> boxes;
    world_->quadtree.getAllBoxes(boxes);

    for (const auto &box: boxes) {
        sf::RectangleShape rectBox(sf::Vector2f(box.width, box.height));
        rectBox.setPosition(box.left, box.top);
        rectBox.setFillColor(sf::Color::Transparent);
        rectBox.setOutlineColor(sf::Color::Green);
        rectBox.setOutlineThickness(1.0f);
        window_->draw(rectBox);
    }
}
