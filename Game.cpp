#include "Game.h"
#include "Fire.h"
#include "Score.h"
#include "Ghost.h"
#include "Map.h"
#include "Wall.h"
#include <iostream>

using namespace std;

Game::Game() : Component(NULL) {
    this->game = this;
}

Game::~Game() {
}

void Game::load(int time) {
    this->main_character = new Pacman(this);
    this->main_character->setPosition(500, 500);
    components.push_back(this->main_character);

//    for (int i = 0; i < 5; i++) {
//        Score *score = new Score(this);
//        float x = (i + 1) * 100;
//        float y = (i + 1) * 100;
//        score->setPosition(x, y);
//        components.push_back(score);
//    }

//    for (int i = 0; i < 5; i++) {
//        Ghost *ghost = new Ghost(this);
//        float x = (i + 1) * 200;
//        float y = (i + 1) * 140;
//        ghost->setPosition(x, y);
//        components.push_back(ghost);
//    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (Map::map[i][j] == 'B') {
                Wall *wall = new Wall(this);
                wall->setPosition(40 * j, 40 * (24 - i), 0);
                components.push_back(wall);
                main_character->walls.push_back(wall);
            }

        }
    }
    for (auto &component : components)
        component->load(time);
}

void Game::update(int time) {
    for (auto &component : components)
        component->update(time);
    Score *score;
    Ghost *ghost;
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        if ((score = dynamic_cast<Score *>(*iter)) != nullptr) {
            if (abs(main_character->getX() - score->getX()) < 25 && abs(main_character->getY() - score->getY()) < 25) {
                components.erase(iter--);
            }
        } else if ((ghost = dynamic_cast<Ghost *>(*iter)) != nullptr) {
            if (abs(main_character->getX() - ghost->getX()) < 25 && abs(main_character->getY() - ghost->getY()) < 25) {
                components.erase(iter--);
            }
        }
    }
}

void Game::render(int time) {
    for (auto &component : components)
        component->render(time);
}

void Game::keyboard(int time, int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            this->main_character->up(time);
            break;
        case GLUT_KEY_DOWN:
            this->main_character->down(time);
            break;
        case GLUT_KEY_LEFT:
            this->main_character->left(time);
            break;
        case GLUT_KEY_RIGHT:
            this->main_character->right(time);
            break;
    }
}

void Game::keyboard_up(int time, int key, int x, int y) {
    this->main_character->stop(time);
}
