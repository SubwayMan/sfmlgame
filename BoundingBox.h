#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <iostream>
#include <vector>

class BoundingBox {
    public:
        sf::Vector2f position;
        double width, height;
        BoundingBox(double x, double y, double w, double h);
        void moveTo(double x, double y);
        void move(double x, double y);
};
