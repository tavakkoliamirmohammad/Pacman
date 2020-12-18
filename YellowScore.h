#ifndef PACMAN_GAME_YELLOWSCORE_H
#define PACMAN_GAME_YELLOWSCORE_H

#include "Score.h"
#include "Component.h"

class YellowScore : public Score {
public:
    YellowScore(Component *parent);

    void load(int time);
};

#endif //PACMAN_GAME_YELLOWSCORE_H
