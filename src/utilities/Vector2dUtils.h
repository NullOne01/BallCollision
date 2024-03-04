#ifndef BALLCOLLISION_VECTOR2DUTILS_H
#define BALLCOLLISION_VECTOR2DUTILS_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Math {
    class Vector2dUtils {
    public:
        static sf::Vector2f getFromToVec(const sf::Vector2f &point1, const sf::Vector2f &point2) {
            return {point2.x - point1.x, point2.y - point1.y};
        }

        static sf::Vector2f getUnit(const sf::Vector2f &vec) {
            float magnitude = getMagnitude(vec);
            return {vec.x / magnitude, vec.y / magnitude};
        }

        static float getMagnitude(const sf::Vector2f &vec) {
            return (float) std::sqrt(getMagnitudeSqr(vec));
        }

        static float getMagnitudeSqr(const sf::Vector2f &vec) {
            return vec.x * vec.x + vec.y * vec.y;
        }

        static float getDistance(const sf::Vector2f &point1, const sf::Vector2f &point2) {
            return getMagnitude(getFromToVec(point1, point2));
        }

        static float getDistanceSqr(const sf::Vector2f &point1, const sf::Vector2f &point2) {
            return getMagnitudeSqr(getFromToVec(point1, point2));
        }

        static sf::Vector2f getDistanceUnitVec(const sf::Vector2f &point1, const sf::Vector2f &point2) {
            return getUnit(getFromToVec(point1, point2));
        }

        static float dotProduct(const sf::Vector2f &vec1, const sf::Vector2f &vec2) {
            return vec1.x * vec2.x + vec1.y * vec2.y;
        }
    };
}

#endif //BALLCOLLISION_VECTOR2DUTILS_H
