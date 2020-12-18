#include "Component.h"
#include "GameState.h"

Component::Component(Component *parent) {
    parent_component = parent;
    if (parent != NULL) game = parent->game;
    else game = NULL;
}

void Component::load(int time) {
    created_time = time;
}

bool Component::isNextStateBlocked(float nextX, float nextY) {
    for (auto &wall : GameState::walls) {
        if (abs(nextX - wall->getX()) < 40 && abs(nextY - wall->getY()) < 40) {
            return true;
        }
    }
    return false;
}