#include "Ghost.h"
#include <SOIL.h>;


Ghost::Ghost(Component *parent) : Component(parent) {
}

void Ghost::load(int time) {
    Component::load(time);

    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/pacman_sprite.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Ghost::update(int time) {
    if (this->is_run) {
        this->frame = (time - this->start_move_time) / 100;
        switch (this->direction) {
            case CharacterDirection::Up:
                this->y += this->frame * .1;
                break;
            case CharacterDirection::Down:
                this->y -= this->frame * .1;
                break;
            case CharacterDirection::Left:
                this->x -= this->frame * .1;
                break;
            case CharacterDirection::Right:
            default:
                this->x += this->frame * .1;
                break;
        }
    } else {
        this->frame = 0;
    }
}

void Ghost::render(int time) {
    auto f = (float) (this->frame % 3);
    auto tx_w = 48;
    auto tx_h = 64;
    auto tx_x = f / 3.0;
    auto tx_y = 3.0 / 4;

    switch (this->direction) {
        case CharacterDirection::Up:
            tx_y = 1.0 / 4;
            break;
        case CharacterDirection::Down:
            tx_y = 0.0 / 4;
            break;
        case CharacterDirection::Left:
            tx_y = 2.0 / 4;
            break;
        case CharacterDirection::Right:
        default:
            tx_y = 3.0 / 4;
            break;
    }

    glBindTexture(GL_TEXTURE_2D, texture_id);

    glPushMatrix();
    glTranslatef(this->x, this->y, 0);

    glBegin(GL_POLYGON);
    glTexCoord2f(tx_x, tx_y);
    glVertex2f(0, 0);
    glTexCoord2f(tx_x + 1.0 / 3, tx_y);
    glVertex2f(tx_w, 0);
    glTexCoord2f(tx_x + 1.0 / 3, tx_y + 1.0 / 4.0);
    glVertex2f(tx_w, tx_h);
    glTexCoord2f(tx_x, tx_y + 1.0 / 4.0);
    glVertex2f(0, tx_h);
    glEnd();

    glPopMatrix();
}

void Ghost::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

float Ghost::getX() const {
    return x;
}

float Ghost::getY() const {
    return y;
}

