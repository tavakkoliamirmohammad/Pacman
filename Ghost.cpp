#include "Ghost.h"
#include <SOIL.h>


Ghost::Ghost(Component *parent) : Component(parent) {
}

void Ghost::load(int time) {
    Component::load(time);

    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/ghost_sprite.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Ghost::update(int time) {
    this->frame = (time - this->start_move_time) / 100;
    float x = this->x;
    float y = this->y;
    switch (this->direction) {
        case CharacterDirection::Up:
            y += this->frame * .1;
            break;
        case CharacterDirection::Down:
            y -= this->frame * .1;
            break;
        case CharacterDirection::Left:
            x -= this->frame * .1;
            break;
        case CharacterDirection::Right:
        default:
            x += this->frame * .1;
            break;
    }
    if (!isNextStateBlocked(x, y)) {
        this->x = x;
        this->y = y;
    } else {
        switch (nextDirectionBlocked()) {
            case None:
                break;
            case CharacterDirection::Up:
                up(time);
                break;
            case CharacterDirection::Right:
                right(time);
                break;
            case CharacterDirection::Down:
                down(time);
                break;
            case CharacterDirection::Left:
                left(time);
                break;
        }
    }
}

void Ghost::render(int time) {
    auto f = (float) (this->frame % 2);
    auto tx_w = 40;
    auto tx_h = 40;
    auto tx_x = f / 2;
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
    glTexCoord2f(tx_x + 1.0 / 2, tx_y);
    glVertex2f(tx_w, 0);
    glTexCoord2f(tx_x + 1.0 / 2, tx_y + 1.0 / 4.0);
    glVertex2f(tx_w, tx_h);
    glTexCoord2f(tx_x, tx_y + 1.0 / 4.0);
    glVertex2f(0, tx_h);
    glEnd();

    glPopMatrix();
}

Movable::CharacterDirection Ghost::nextDirectionBlocked() {
    switch (this->direction) {
        case CharacterDirection::Up:
            return CharacterDirection::Right;
        case CharacterDirection::Right:
            return CharacterDirection::Down;
        case CharacterDirection::Down:
            return CharacterDirection::Left;
        case CharacterDirection::Left:
            return CharacterDirection::Up;
    }
    return CharacterDirection::Up;
}

void Ghost::up(int time) {
    if (this->direction == CharacterDirection::Up) {
        return;
    }

    this->start_move_time = time;
    this->direction = CharacterDirection::Up;
}

void Ghost::down(int time) {
    if (this->direction == CharacterDirection::Down) {
        return;
    }

    this->start_move_time = time;
    this->direction = CharacterDirection::Down;
}

void Ghost::left(int time) {
    if (this->direction == CharacterDirection::Left) {
        return;
    }

    this->start_move_time = time;
    this->direction = CharacterDirection::Left;
}

void Ghost::right(int time) {
    if (this->direction == CharacterDirection::Right) {
        return;
    }

    this->start_move_time = time;
    this->direction = CharacterDirection::Right;
}
