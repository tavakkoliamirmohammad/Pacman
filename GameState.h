
#ifndef PACMAN_GAME_GAMESTATE_H
#define PACMAN_GAME_GAMESTATE_H


#include "Wall.h"
#include "Ghost.h"
#include "Score.h"
#include "Pacman.h"

#include <vector>


class GameState {
public:
    static std::vector<Wall *> walls;
    static std::vector<Ghost *> ghosts;
    static std::vector<Pacman *> pacmans;
    static std::vector<Score *> scores;

    static bool isPositionBlocked(float x, float y);

};

#endif //PACMAN_GAME_GAMESTATE_H
