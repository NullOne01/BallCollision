#ifndef BALLCOLLISION_RECTUTILS_H
#define BALLCOLLISION_RECTUTILS_H

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <SFML/Graphics/Rect.hpp>

namespace Math {
    class RectUtils {
    public:
        static sf::Vector2f getTopLeft(const sf::FloatRect &rect) noexcept {
            return {rect.left, rect.top};
        }

        static sf::Vector2f getCenter(const sf::FloatRect &rect) noexcept {
            return {rect.left + rect.width / 2, rect.top + rect.height / 2};
        }

        static float getRight(const sf::FloatRect &rect) noexcept {
            return rect.left + rect.width;
        }

        static float getBottom(const sf::FloatRect &rect) noexcept {
            return rect.top + rect.height;
        }
    };
}

#endif //BALLCOLLISION_RECTUTILS_H
