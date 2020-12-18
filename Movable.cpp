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

bool Movable::isNextStateBlocked(float nextX, float nextY) {
    for (auto &wall : this->walls) {
        if (abs(nextX - wall->getX()) < 40 && abs(nextY - wall->getY()) < 40) {
            return true;
        }
    }
    return false;
}
