#include "Score.h"
#include <SOIL.h>

Score::Score(Component *parent) : Component(parent) {

}

void Score::load(int time) {
    Component::load(time);
}

void Score::update(int time) {

}

void Score::render(int time) {
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

void Score::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

int Score::getScore() {
    return this->score;
}

float Score::getX() const {
    return x;
}

float Score::getY() const {
    return y;
}