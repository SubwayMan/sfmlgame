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
#include <set>

//forward declaration
class GameManager;
class Player;

class GameObject {
    public:
        sf::Vector2f position;
        sf::Sprite sprite;
        bool isCollider;
        std::set<GameObject*> colliders;
        BoundingBox *bb;
        GameManager *GM;

        
        GameObject(double x, double y, double w, double h, GameManager *GM);
        ~GameObject();
        // Scale the sprite to the object's bounding box
        void scaleToSize();
        virtual void loop() = 0;
        void setPosition(const sf::Vector2f &);
        void move(const sf::Vector2f &);
        void setTexture(const std::string &);
        void markAsCollider();
        void updateColliders();

    protected:
        // Texture must exist so long as the sprite intends to refer to it
        sf::Texture texture;
        sf::Vector2u textureSize;
};

class Portal: public GameObject {
    using GameObject::GameObject;
    public:
        void loop() override;
        Player *player;
        Portal(Player *p);

    protected:
        Portal* alt=0;

};

class Blank: public GameObject {
    using GameObject::GameObject;
    public:
        void loop() override;
        Player *player;
};
