#ifndef BALLCOLLISION_GAME_H
#define BALLCOLLISION_GAME_H


#include "../entity/World.h"
#include "../system/SystemBase.h"

class Game {
public:
    Game();

    void start();

private:
    std::unique_ptr<sf::RenderWindow> window_;
    std::unique_ptr<World> world_;
    std::vector<std::unique_ptr<SystemBase>> systems_;

    void initWorld();

    void initSystems();
};


#endif //BALLCOLLISION_GAME_H
