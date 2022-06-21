#include "headers/GameObject.h"
#include "headers/BoundingBox.h"
#include "headers/GameManager.h"
#include "headers/functions.h"
#include <SFML/System/Vector2.hpp>

GameObject::GameObject(double x, double y, double w, double h, std::string texture, GameManager* GM) {
    this->texture.loadFromFile(texture);
    this->textureSize = this->texture.getSize();
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(x, y);
    this->bb = new BoundingBox(x, y, w, h);
    this->position.x = x;
    this->position.y = y;
    this->GM = GM;
}

GameObject::~GameObject() {
    delete this->bb;
}

void GameObject::scaleToSize() {
    double scaleX = this->bb->width/this->textureSize.x;
    double scaleY = this->bb->height/this->textureSize.y;
    this->sprite.setScale(scaleX, scaleY);
}

void GameObject::setPosition(const sf::Vector2f &pos) {
    this->position = pos;
    this->bb->moveTo(pos);
    this->sprite.setPosition(pos);
    this->updateColliders();
}

void GameObject::move(const sf::Vector2f &v) {
    this->position += v;
    this->bb->move(v);
    this->sprite.setPosition(this->position + v);
    this->updateColliders();
}

void GameObject::markAsCollider() {
    this->isCollider = true;
    this->updateColliders();
}

void GameObject::updateColliders() {
    // update colliding lists of all previous colliders
    for (GameObject *e: this->colliders) {
        e->colliders.erase(this);
    }
    this->colliders.clear();

    // add all new colliders from game manager
    for (GameObject *e: this->GM->colliders) {
        if (this == e) continue;
        if (getCollision(*this->bb, *e->bb)) {
            this->colliders.insert(e);
            e->colliders.insert(this);
        }
    }
}

void Blank::loop() {
    if (!this->colliders.empty()) {
        sf::Vector2f v(3, 3);
        this->move(v);
    }
}

