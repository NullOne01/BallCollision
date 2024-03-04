#ifndef BALLCOLLISION_MOVEMENTSYSTEM_H
#define BALLCOLLISION_MOVEMENTSYSTEM_H


#include "SystemBase.h"

class MovementSystem : public SystemBase {
public:
    explicit MovementSystem(World *world);

    void update(float deltaTime) override;

private:

    void moveBall(Ball &ball, float deltaTime);
};


#endif //BALLCOLLISION_MOVEMENTSYSTEM_H
