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
}

void GameObject::move(const sf::Vector2f &v) {
    this->position += v;
    this->bb->move(v);
    this->sprite.setPosition(this->position + v);
}

void GameObject::markAsCollider(std::vector<GameObject *> &objs) {
    this->isCollider = true;
    for (GameObject *e: objs) {
        if (getCollision(*this->bb, *e->bb)) {
            this->colliders.insert(e);
        }
    }
}
