#ifndef BALLCOLLISION_DRAWCOLLISIONSYSTEM_H
#define BALLCOLLISION_DRAWCOLLISIONSYSTEM_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../entity/World.h"
#include "SystemBase.h"

class DrawCollisionSystem : public SystemBase {
public:
    explicit DrawCollisionSystem(sf::RenderWindow *window, World *world);

    void update(float deltaTime) override;

private:
    sf::RenderWindow *window_;

    void drawQuadtree();
};


#endif //BALLCOLLISION_DRAWCOLLISIONSYSTEM_H
