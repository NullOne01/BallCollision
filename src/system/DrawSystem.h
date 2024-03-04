#ifndef BALLCOLLISION_DRAWSYSTEM_H
#define BALLCOLLISION_DRAWSYSTEM_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "SystemBase.h"

class DrawSystem : public SystemBase {
public:
    explicit DrawSystem(sf::RenderWindow *window, World *world);

    void update(float deltaTime) override;

private:
    sf::RenderWindow *window_;

    void drawBall(const Ball &ball);
};


#endif //BALLCOLLISION_DRAWSYSTEM_H
