#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class GameObject {
    public:
        sf::Vector2f position;


};

class BoundingBox {
    public:
        sf::Vector2f position;
        double width, height;
        BoundingBox(double x, double y, double w, double h);
};
