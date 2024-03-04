#include "MovementSystem.h"

MovementSystem::MovementSystem(World *world) : SystemBase(world) {}

void MovementSystem::update(float deltaTime) {
    for (auto &ball: world_->balls) {
        moveBall(ball, deltaTime);
    }
}

void MovementSystem::moveBall(Ball &ball, float deltaTime) {
    float dx = ball.velocity.x * deltaTime;
    float dy = ball.velocity.y * deltaTime;
    ball.position.x += dx;
    ball.position.y += dy;
}

