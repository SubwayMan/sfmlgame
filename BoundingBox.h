#pragma once
#include <SFML/System/Vector2.hpp>

class BoundingBox {
    public:
        sf::Vector2f position;
        double width, height;
        BoundingBox(double x, double y, double w, double h);
        void moveTo(const sf::Vector2f &);
        void move(const sf::Vector2f &);
};
