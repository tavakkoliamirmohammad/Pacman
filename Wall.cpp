#include "Wall.h"
#include <SOIL.h>

Wall::Wall(Component *parent) :
        Component(parent) {
}

float Wall::getX() {
    return x;
}

float Wall::getY() {
    return y;
}

void Wall::load(int time) {
    Component::load(time);

    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/stone.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_INVERT_Y);
}

void Wall::update(int time) {

}

void Wall::render(int time) {
    auto tx_w = 40;
    auto tx_h = 40;

    glBindTexture(GL_TEXTURE_2D, texture_id);
    glPushMatrix();
    glTranslatef(this->x, this->y, 0);

    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex2f(0, 0);
    glTexCoord2f(1.0, 0);
    glVertex2f(tx_w, 0);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(tx_w, tx_h);
    glTexCoord2f(0, 1.0);
    glVertex2f(0, tx_h);
    glEnd();

    glPopMatrix();
}

void Wall::setPosition(float x, float y, float angle) {
    this->x = x;
    this->y = y;
}
