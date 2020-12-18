#include "YellowScore.h"
#include <SOIL.h>

YellowScore::YellowScore(Component *parent) : Score(parent) {
    this->score = 5;
}

void YellowScore::load(int time) {
    Score::load(time);
    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/dot.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}
