#ifndef BALLCOLLISION_FPSDEBUGSYSTEM_H
#define BALLCOLLISION_FPSDEBUGSYSTEM_H


#include "SystemBase.h"
#include "../utilities/MiddleAverageFilter.h"

class FpsDebugSystem : public SystemBase {
public:
    explicit FpsDebugSystem(sf::RenderWindow *window, World *world);

    void update(float deltaTime) override;

private:
    sf::RenderWindow *window_;
    Math::MiddleAverageFilter<float, 100> fpsCounter_;

    void drawFps(float fps);
};


#endif //BALLCOLLISION_FPSDEBUGSYSTEM_H
