#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "Game.h"
#include "../entity/World.h"
#include "../MiddleAverageFilter.h"
#include "../system/SystemBase.h"
#include "../system/DrawSystem.h"
#include "../system/MovementSystem.h"
#include "../system/FpsDebugSystem.h"

constexpr int WINDOW_X = 1024;
constexpr int WINDOW_Y = 768;
constexpr int MAX_BALLS = 300;
constexpr int MIN_BALLS = 100;

Game::Game() {}

void Game::start() {
    window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(WINDOW_X, WINDOW_Y), "ball collision demo");
    srand(time(NULL));

    initWorld();
    initSystems();

    // window_.setFramerateLimit(60);

    sf::Clock clock;
    float lastime = clock.restart().asSeconds();

    while (window_->isOpen()) {

        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
        }

        float current_time = clock.getElapsedTime().asSeconds();
        float deltaTime = current_time - lastime;

        /// <summary>
        /// TODO: PLACE COLLISION CODE HERE
        /// объекты создаются в случайном месте на плоскости со случайным вектором скорости, имеют радиус R
        /// Объекты движутся кинетически. Пространство ограниченно границами окна
        /// Напишите обработчик столкновений шаров между собой и краями окна. Как это сделать эффективно?
        /// Массы пропорцианальны площадям кругов, описывающих объекты
        /// Как можно было-бы улучшить текущую архитектуру кода?
        /// Данный код является макетом, вы можете его модифицировать по своему усмотрению

        for (const auto &system: systems_) {
            system->update(deltaTime);
        }

        window_->display();
        lastime = current_time;
    }
}

void Game::initSystems() {
    systems_.push_back(std::make_unique<DrawSystem>(window_.get(), world_.get()));
    systems_.push_back(std::make_unique<FpsDebugSystem>(window_.get(), world_.get()));
    systems_.push_back(std::make_unique<MovementSystem>(world_.get()));
}

void Game::initWorld() {
    world_ = std::make_unique<World>();

    for (int i = 0; i < (rand() % (MAX_BALLS - MIN_BALLS) + MIN_BALLS); i++) {
        Ball newBall;
        newBall.position.x = rand() % WINDOW_X;
        newBall.position.y = rand() % WINDOW_Y;
        newBall.direction.x = (-5 + (rand() % 10)) / 3.;
        newBall.direction.y = (-5 + (rand() % 10)) / 3.;
        newBall.radius = 5 + rand() % 5;
        newBall.speed = 30 + rand() % 30;
        world_->balls.push_back(newBall);
    }
}
