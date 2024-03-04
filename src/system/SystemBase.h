#ifndef BALLCOLLISION_SYSTEMBASE_H
#define BALLCOLLISION_SYSTEMBASE_H


#include "../entity/World.h"

class SystemBase {
public:
    virtual void update(float deltaTime) = 0;

protected:
    World *world_;

    explicit SystemBase(World *world);
};


#endif //BALLCOLLISION_SYSTEMBASE_H
