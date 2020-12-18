#include "GameState.h"
#include "Wall.h"
#include "Ghost.h"
#include "Score.h"
#include "Pacman.h"


vector<Wall *> GameState::walls;
vector<Ghost *> GameState::ghosts;
vector<Score *> GameState::scores;
vector<Pacman *> GameState::pacmans;


bool GameState::isPositionBlocked(float x, float y) {
    for (Wall *wall : walls) {
        if (abs(x - wall->getX()) < 40 && abs(y - wall->getY()) < 40) {
            return true;
        }
    }
    for (Ghost *ghost: ghosts) {
        if (abs(x - ghost->getX()) < 40 && abs(y - ghost->getY()) < 40) {
            return true;
        }
    }
    for (Score *score: scores) {
        if (abs(x - score->getX()) < 40 && abs(y - score->getY()) < 40) {
            return true;
        }
    }
    for (Pacman *pacman: pacmans) {
        if (abs(x - pacman->getX()) < 40 && abs(y - pacman->getY()) < 40) {
            return true;
        }
    }
    return false;
};
