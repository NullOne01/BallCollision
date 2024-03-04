#ifndef BALLCOLLISION_BALL_H
#define BALLCOLLISION_BALL_H


#include <SFML/System/Vector2.hpp>

struct Ball {
    sf::Vector2f position;
    float radius = 0;

    // NOTICE_ME_SENPAI: Removed direction and speed to make velocity.
    sf::Vector2f velocity;
};


#endif //BALLCOLLISION_BALL_H
