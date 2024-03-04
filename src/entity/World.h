#ifndef BALLCOLLISION_WORLD_H
#define BALLCOLLISION_WORLD_H


#include <vector>
#include "Ball.h"
#include "../utilities/Quadtree.h"

struct World {
    std::vector<Ball> balls;

    quadtree::Quadtree<Ball*, GetBallBox> quadtree;

    sf::FloatRect worldSize;

    explicit World(const sf::FloatRect &worldSize);
};


#endif //BALLCOLLISION_WORLD_H
