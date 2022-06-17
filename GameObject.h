#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include "BoundingBox.h"
#include <string>
#include <iostream>
#include <vector>

class GameObject {
    public:
        sf::Vector2f position;
        sf::Sprite sprite;
        BoundingBox *bb;
        
        GameObject(double x, double y, double w, double h, std::string texture);
        ~GameObject();
        // Scale the sprite to the object's bounding box
        void scaleToSize();
        void loop();
    protected:
        // Texture must exist so long as the sprite intends to refer to it
        sf::Texture texture;
        sf::Vector2u textureSize;
};

