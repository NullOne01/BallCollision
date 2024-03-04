#ifndef BALLCOLLISION_SYSTEMBASE_H
#define BALLCOLLISION_SYSTEMBASE_H


#include "../entity/World.h"

class SystemBase {
public:

    explicit SystemBase(World *world);

    virtual ~SystemBase() = default;

    virtual void update(float deltaTime) = 0;

protected:
    World *world_;
};


#endif //BALLCOLLISION_SYSTEMBASE_H
