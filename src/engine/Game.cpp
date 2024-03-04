#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "Game.h"
#include "../utilities/MiddleAverageFilter.h"
#include "../system/DrawSystem.h"
#include "../system/MovementSystem.h"
#include "../system/FpsDebugSystem.h"
#include "../system/CollisionSystem.h"
#include "../system/DrawCollisionSystem.h"

constexpr int WINDOW_X = 1024;
constexpr int WINDOW_Y = 768;
constexpr int MAX_BALLS = 300;
constexpr int MIN_BALLS = 100;

Game::Game() = default;

void Game::start() {
    window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_X, WINDOW_Y), "ball collision demo");
    srand(time(nullptr));

    initWorld();
    initSystems();

    sf::Clock clock;
    float lastTime = clock.restart().asSeconds();

    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
        }

        float current_time = clock.getElapsedTime().asSeconds();
        float deltaTime = current_time - lastTime;

        window_->clear();
        for (const auto &system: systems_) {
            system->update(deltaTime);
        }
        window_->display();
        lastTime = current_time;
    }
}

void Game::initSystems() {
    systems_.push_back(std::make_unique<DrawSystem>(window_.get(), world_.get()));
    systems_.push_back(std::make_unique<FpsDebugSystem>(window_.get(), world_.get()));
    systems_.push_back(std::make_unique<MovementSystem>(world_.get()));
    systems_.push_back(std::make_unique<CollisionSystem>(window_.get(), world_.get()));
    // Warning: DrawCollisionSystem is highly unoptimized. Should be used only for debug purposes.
    //systems_.push_back(std::make_unique<DrawCollisionSystem>(window_.get(), world_.get()));
}

void Game::initWorld() {
    world_ = std::make_unique<World>(
            sf::FloatRect(0, 0, static_cast<float>(window_->getSize().x), static_cast<float>(window_->getSize().y)));

    for (int i = 0; i < (rand() % (MAX_BALLS - MIN_BALLS) + MIN_BALLS); i++) {
        Ball newBall;
        newBall.position.x = rand() % WINDOW_X;
        newBall.position.y = rand() % WINDOW_Y;

        sf::Vector2f velocityDirection = {static_cast<float>((-5 + (rand() % 10)) / 3.),
                                          static_cast<float>((-5 + (rand() % 10)) / 3.)};
        float velocityMagnitude = 30 + rand() % 30;
        newBall.velocity = velocityDirection * velocityMagnitude;
        newBall.radius = 5 + rand() % 5;
        world_->balls.push_back(newBall);
    }
}
