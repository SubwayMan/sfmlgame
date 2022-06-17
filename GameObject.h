#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>

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
        // Texture must exist so long as the sprite intends to refer to it
        sf::Texture texture;
        sf::Vector2u textureSize;
};

GameObject::GameObject(double x, double y, double w, double h, std::string texture) {
    this->texture.loadFromFile(texture);
    this->textureSize = this->texture.getSize();
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(x, y);
    this->bb = new BoundingBox(x, y, w, h);
}

GameObject::~GameObject() {
    delete this->bb;
}

void GameObject::scaleToSize() {
    double scaleX = this->bb->width/this->textureSize.x;
    double scaleY = this->bb->height/this->textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
}
