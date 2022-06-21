#include "headers/BoundingBox.h"
#include <SFML/System/Vector2.hpp>

void BoundingBox::move(const sf::Vector2f &v) {
    this->position += v;
}

void BoundingBox::moveTo(const sf::Vector2f &v) {
    this->position = v;
}

BoundingBox::BoundingBox(double x, double y, double w, double h) {
    this->moveTo(sf::Vector2f(x, y));
    this->width = w;
    this->height = h;
}

