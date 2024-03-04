#ifndef BALLCOLLISION_BALL_H
#define BALLCOLLISION_BALL_H


#include <SFML/System/Vector2.hpp>

struct Ball {
    sf::Vector2f position;
    sf::Vector2f direction;
    float radius = 0;
    float speed = 0;

    // NOTICE_ME_SENPAI: Removed direction and speed to make velocity.
    sf::Vector2f velocity;
};


#endif //BALLCOLLISION_BALL_H
