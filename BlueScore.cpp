#include "BlueScore.h"

#include <SOIL.h>

BlueScore::BlueScore(Component *parent) : Score(parent) {
    this->score = 10;
}

void BlueScore::load(int time) {
    Score::load(time);
    texture_id = SOIL_load_OGL_texture("./Sprites/dotitem.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}
