#ifndef BALLCOLLISION_COLLISIONSYSTEM_H
#define BALLCOLLISION_COLLISIONSYSTEM_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "SystemBase.h"
#include "../utilities/Vector2dUtils.h"

class CollisionSystem : public SystemBase {
public:
    CollisionSystem(sf::RenderWindow *window, World *world);

    void update(float deltaTime) override;

private:
    sf::RenderWindow *window_;

    void collideBorders(Ball &ball);

    bool areIntersected(const Ball &ball1, const Ball &ball2);

    void collideOthers(Ball &ball);

    void collideBalls(Ball &ball1, Ball &ball2);
};


#endif //BALLCOLLISION_COLLISIONSYSTEM_H
