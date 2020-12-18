#include "Pacman.h"
#include "SOIL.h"
#include <iostream>

using namespace std;

Pacman::Pacman(Component *parent) : Component(parent) {
}

void Pacman::load(int time) {
    Component::load(time);

    texture_id = SOIL_load_OGL_texture("/home/amir/projects/pacman_game/Sprites/pacman_sprite.png", SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Pacman::update(int time) {
    if (this->is_run) {
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
        if(!isNextStateBlocked(x, y)){
            this->x = x;
            this->y = y;
        }
    } else {
        this->frame = 0;
    }
}

void Pacman::render(int time) {
    auto f = (float) (this->frame % 3);
    auto tx_w = 40;
    auto tx_h = 40;
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

void Pacman::up(int time) {
    if (this->is_run && this->direction == CharacterDirection::Up) {
        return;
    }

    this->is_run = true;
    this->start_move_time = time;
    this->direction = CharacterDirection::Up;
}

void Pacman::down(int time) {
    if (this->is_run && this->direction == CharacterDirection::Down) {
        return;
    }

    this->is_run = true;
    this->start_move_time = time;
    this->direction = CharacterDirection::Down;
}

void Pacman::left(int time) {
    if (this->is_run && this->direction == CharacterDirection::Left) {
        return;
    }

    this->is_run = true;
    this->start_move_time = time;
    this->direction = CharacterDirection::Left;
}

void Pacman::right(int time) {
    if (this->is_run && this->direction == CharacterDirection::Right) {
        return;
    }

    this->is_run = true;
    this->start_move_time = time;
    this->direction = CharacterDirection::Right;
}

void Pacman::stop(int time) {
    this->is_run = false;
}
