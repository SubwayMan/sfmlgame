#include "headers/functions.h"
#include "headers/GameObject.h"

bool getCollision(BoundingBox &a, BoundingBox &b) {
    return !(a.position.x >= b.position.x + b.width ||
            b.position.x >= a.position.x + a.width ||
            a.position.y >= b.position.y + b.height ||
            b.position.y >= a.position.y + a.height);
}


