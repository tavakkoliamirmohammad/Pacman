#ifndef PACMAN_GAME_BLUESCORE_H
#define PACMAN_GAME_BLUESCORE_H

#include "Score.h"
#include "Component.h"

class BlueScore : public Score {

public:
    BlueScore(Component *parent);

    void load(int time);
};

#endif //PACMAN_GAME_BLUESCORE_H
