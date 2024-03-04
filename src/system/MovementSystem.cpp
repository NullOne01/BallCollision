#include "MovementSystem.h"

MovementSystem::MovementSystem(World *world) : SystemBase(world) {}

void MovementSystem::update(float deltaTime) {
    for (auto &ball: world_->balls) {
        moveBall(ball, deltaTime);
    }
}

void MovementSystem::moveBall(Ball &ball, float deltaTime) {
    float dx = ball.direction.x * ball.speed * deltaTime;
    float dy = ball.direction.y * ball.speed * deltaTime;
    ball.position.x += dx;
    ball.position.y += dy;
}

