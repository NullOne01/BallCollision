#include "World.h"

World::World(const sf::FloatRect &worldSize) : worldSize(worldSize), quadtree(worldSize) {
}
