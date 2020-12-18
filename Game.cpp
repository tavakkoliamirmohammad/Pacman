#include "Game.h"
#include "Score.h"
#include "Ghost.h"
#include "Map.h"
#include "Wall.h"
#include "GameState.h"
#include <iostream>
#include <ctime>

using namespace std;

Game::Game() : Component(NULL) {
    this->game = this;
}

Game::~Game() {
}

void Game::load(int time1) {
    srand(time(0));
    this->main_character = new Pacman(this);
    components.push_back(this->main_character);

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            if (Map::map[i][j] == 'B') {
                Wall *wall = new Wall(this);
                wall->setPosition(40 * j, 40 * (24 - i), 0);
                components.push_back(wall);
                GameState::walls.push_back(wall);
            }

        }
    }
    for (int i = 0; i < 5; i++) {
        Ghost *ghost = new Ghost(this);
        int x = ((double) rand() / (RAND_MAX)) * 25;
        int y = ((double) rand() / (RAND_MAX)) * 25;
        while (GameState::isPositionBlocked(x * 40, y * 40)) {
            x = ((double) rand() / (RAND_MAX)) * 25;
            y = ((double) rand() / (RAND_MAX)) * 25;
        }
        ghost->setPosition(x * 40, y * 40);
        components.push_back(ghost);
        GameState::ghosts.push_back(ghost);
    }

    for (int i = 0; i < 5; i++) {
        Score *score = new Score(this);
        int x = ((double) rand() / (RAND_MAX)) * 25;
        int y = ((double) rand() / (RAND_MAX)) * 25;
        while (GameState::isPositionBlocked(x * 40, y * 40)) {
            x = ((double) rand() / (RAND_MAX)) * 25;
            y = ((double) rand() / (RAND_MAX)) * 25;
        }
        score->setPosition(x * 40, y * 40);
        GameState::scores.push_back(score);
        components.push_back(score);
    }
    int x = ((double) rand() / (RAND_MAX)) * 25;
    int y = ((double) rand() / (RAND_MAX)) * 25;
    while (GameState::isPositionBlocked(x * 40, y * 40)) {
        x = ((double) rand() / (RAND_MAX)) * 25;
        y = ((double) rand() / (RAND_MAX)) * 25;
    }
    this->main_character->setPosition(x * 40, y * 40);
    GameState::pacmans.push_back(this->main_character);

    for (auto &component : components)
        component->load(time1);
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
