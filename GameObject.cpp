#include "GameObject.h"
#include "BoundingBox.h"

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

