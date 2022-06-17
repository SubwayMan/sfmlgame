#include "BoundingBox.h"

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

