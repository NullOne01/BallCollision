#ifndef BALLCOLLISION_BALL_H
#define BALLCOLLISION_BALL_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>

struct Ball {
    sf::Vector2f position;
    float radius = 0;
    sf::Color color = sf::Color::White;

    // NOTICE_ME_SENPAI: Removed direction and speed to make velocity.
    sf::Vector2f velocity;
};

struct GetBallBox {
    sf::FloatRect operator()(const Ball *ball) const {
        return {ball->position.x - ball->radius, ball->position.y - ball->radius, ball->radius * 2, ball->radius * 2};
    }
};


#endif //BALLCOLLISION_BALL_H
