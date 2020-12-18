#include "Movable.h"
#include "Map.h"

float Movable::getX() const {
    return x;
}

float Movable::getY() const {
    return y;
}

void Movable::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}
