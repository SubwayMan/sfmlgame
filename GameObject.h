#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class BoundingBox {
    public:
        sf::Vector2f position;
        double width, height;
        BoundingBox(double x, double y, double w, double h);
};

class GameObject {
    public:
        sf::Vector2f position;
        sf::Texture sprite;
        BoundingBox bb;
    
        // Scale the sprite to the object's bounding box
        void scaleToSize();


};

