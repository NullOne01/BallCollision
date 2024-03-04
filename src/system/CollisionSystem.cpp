#include "CollisionSystem.h"
#include "../utilities/Vector2dUtils.h"

CollisionSystem::CollisionSystem(sf::RenderWindow *window, World *world) : SystemBase(world), window_(window) {}

void CollisionSystem::update(float deltaTime) {
    for (auto &ball: world_->balls) {
        collideBorders(ball);
        collideOthers(ball);
    }
}

void CollisionSystem::collideBorders(Ball &ball) {
    if (ball.position.x > window_->getSize().x - ball.radius) {
        ball.velocity.x = -abs(ball.velocity.x);
    }

    if (ball.position.x < 0 + ball.radius) {
        ball.velocity.x = abs(ball.velocity.x);
    }

    if (ball.position.y > window_->getSize().y - ball.radius) {
        ball.velocity.y = -abs(ball.velocity.y);
    }

    if (ball.position.y < 0 + ball.radius) {
        ball.velocity.y = abs(ball.velocity.y);
    }
}

void CollisionSystem::collideOthers(Ball &ball) {
    for (auto &otherBall: world_->balls) {
        if (&ball == &otherBall) {
            continue;
        }

        if (areIntersected(ball, otherBall)) {
            collideBalls(ball, otherBall);
        }
    }
}

//void CollisionSystem::collideBalls(Ball &ball1, Ball &ball2) {
//    // Used: https://www.imada.sdu.dk/u/rolf/Edu/DM815/E10/2dcollisions.pdf
//    // TODO: 100% sure can be optimized.
//
//    float m1 = ball1.radius * ball1.radius;
//    float m2 = ball2.radius * ball2.radius;
//
//    sf::Vector2f v1 = Math::Vector2dUtils::getUnit(ball1.direction) * ball1.speed;
//    sf::Vector2f v2 = Math::Vector2dUtils::getUnit(ball2.direction) * ball2.speed;
//
//    sf::Vector2f un = Math::Vector2dUtils::getDistanceUnitVec(ball1.position, ball2.position);
//    sf::Vector2f ut = {-un.y, un.x};
//
//    float v1n = Math::Vector2dUtils::dotProduct(un, v1);
//    float v1t = Math::Vector2dUtils::dotProduct(ut, v1);
//    float v2n = Math::Vector2dUtils::dotProduct(un, v2);
//    float v2t = Math::Vector2dUtils::dotProduct(ut, v2);
//
//    float v1t_after = v1t;
//    float v2t_after = v2t;
//
//    float v1n_after = (v1n * (m1 - m2) + 2 * m2 * v2n) / (m1 + m2);
//    float v2n_after = (v2n * (m2 - m1) + 2 * m1 * v1n) / (m1 + m2);
//
//    sf::Vector2f v1n_vec_after = Math::Vector2dUtils::multiply(un, v1n_after);
//    sf::Vector2f v1t_vec_after = Math::Vector2dUtils::multiply(ut, v1t_after);
//    sf::Vector2f v2n_vec_after = Math::Vector2dUtils::multiply(un, v2n_after);
//    sf::Vector2f v2t_vec_after = Math::Vector2dUtils::multiply(ut, v2t_after);
//
//    sf::Vector2f v1_vec_after = Math::Vector2dUtils::sum(v1n_vec_after, v1t_vec_after);
//    sf::Vector2f v2_vec_after = Math::Vector2dUtils::sum(v2n_vec_after, v2t_vec_after);
//
//    ball1.direction = Math::Vector2dUtils::getUnit(v1_vec_after);
//    ball1.speed = Math::Vector2dUtils::getMagnitude(v1_vec_after);
//    ball2.direction = Math::Vector2dUtils::getUnit(v2_vec_after);
//    ball2.speed = Math::Vector2dUtils::getMagnitude(v2_vec_after);
//}

void CollisionSystem::collideBalls(Ball &a, Ball &b) {
    float a_mass = a.radius * a.radius;
    float b_mass = b.radius * b.radius;

    sf::Vector2f relativeVelocity = Math::Vector2dUtils::getFromToVec(a.velocity, b.velocity);
    sf::Vector2f relativePosition = Math::Vector2dUtils::getDistanceUnitVec(a.position, b.position);

    float velocityAlongNormal = Math::Vector2dUtils::dotProduct(relativeVelocity, relativePosition);
    if (velocityAlongNormal > 0) {
        return;
    }

    float e = 1.0; // Coefficient of restitution

    float j = -(1 + e) * velocityAlongNormal;
    j /= 1 / a_mass + 1 / b_mass;

    // Apply impulse
    sf::Vector2f impulse = relativePosition * j;
    a.velocity -= impulse / a_mass;
    b.velocity += impulse / b_mass;
}

bool CollisionSystem::areIntersected(const Ball &ball1, const Ball &ball2) {
    float distance = Math::Vector2dUtils::getDistance(ball1.position, ball2.position);
    return distance < ball1.radius + ball2.radius;
}
