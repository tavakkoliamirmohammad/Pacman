#ifndef PACMAN_GAME_MOVABLE_H
#define PACMAN_GAME_MOVABLE_H

#include "Wall.h"
#include <vector>

class Movable {
public:

    enum CharacterDirection {
        None = 0, Up = 1, Right = 2, Down = 3, Left = 4
    };

    void setPosition(int x, int y);

    float getX() const;

    float getY() const;



protected:
    float x;
    float y;

    int start_move_time;
    CharacterDirection direction;

};


#endif //PACMAN_GAME_MOVABLE_H
