#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class BoundingBox {
    public:
        sf::Vector2f position;
        double width, height;
        BoundingBox(double x, double y, double w, double h);
        void moveTo(double x, double y);
        void move(double x, double y);
};

void BoundingBox::move(double x, double y) {
    this->position.x += x;
    this->position.y += y;
}

void BoundingBox::moveTo(double x, double y) {
    this->position.x = x;
    this->position.y = y;
}

BoundingBox::BoundingBox(double x, double y, double w, double h) {
    this->moveTo(x, y);
    this->width = w;
    this->height = h;
}

class GameObject {
    public:
        sf::Vector2f position;
        sf::Sprite sprite;
        BoundingBox *bb;
        
        GameObject(double x, double y, double w, double h, std::string texture);
        ~GameObject();
        // Scale the sprite to the object's bounding box
        void scaleToSize();
    private:
        sf::Vector2u textureSize;
};

GameObject::GameObject(double x, double y, double w, double h, std::string texture) {
    sf::Texture t;
    t.loadFromFile(texture);
    this->sprite.setTexture(t);
    this->sprite.setPosition(x, y);
    this->bb = new BoundingBox(x, y, w, h);
}

GameObject::~GameObject() {
    delete[] this->bb;
}
