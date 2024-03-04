#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(sf::RenderWindow *window, World *world) : SystemBase(world), window_(window) {
}

void CollisionSystem::update(float deltaTime) {
    world_->quadtree.clear();
    for (auto &ball: world_->balls) {
        ball.color = sf::Color::White;
        world_->quadtree.add(&ball);
    }

    for (auto &ball: world_->balls) {
        collideBorders(ball);
        collideOthers(ball);
    }
}

void CollisionSystem::collideBorders(Ball &ball) {
    if (ball.position.x > static_cast<float>(window_->getSize().x) - ball.radius) {
        ball.velocity.x = -abs(ball.velocity.x);
    }

    if (ball.position.x < 0 + ball.radius) {
        ball.velocity.x = abs(ball.velocity.x);
    }

    if (ball.position.y > static_cast<float>(window_->getSize().y) - ball.radius) {
        ball.velocity.y = -abs(ball.velocity.y);
    }

    if (ball.position.y < 0 + ball.radius) {
        ball.velocity.y = abs(ball.velocity.y);
    }
}

void CollisionSystem::collideOthers(Ball &ball) {
    GetBallBox getBallBox;
    sf::FloatRect box = getBallBox(&ball);
    std::vector<Ball *> otherBalls = world_->quadtree.query(box);

    for (auto &otherBall: otherBalls) {
        if (otherBall == &ball) {
            continue;
        }

        if (areIntersected(ball, *otherBall)) {
            ball.color = sf::Color::Red;
            otherBall->color = sf::Color::Red;
            collideBalls(ball, *otherBall);
        }
    }
}

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
