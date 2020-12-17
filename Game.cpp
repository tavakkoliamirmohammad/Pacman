#include "Game.h"
#include "Fire.h"
#include "Score.h"

Game::Game() : Component(NULL) {
    this->game = this;
}

Game::~Game() {
}

void Game::load(int time) {
    this->main_character = new Pacman(this);
    this->main_character->setPosition(500, 500);
    components.push_back(this->main_character);

    for (int i = 0; i < 5; i++) {
        Score *score = new Score(this);
        float x = ((double) rand() / (RAND_MAX)) * 1000;
        float y = ((double) rand() / (RAND_MAX)) * 1000;
        score->setPosition(x, y);
        components.push_back(score);
    }

    for (auto & component : components)
        component->load(time);
}

void Game::update(int time) {
    for (auto & component : components)
        component->update(time);
}

void Game::render(int time) {
    for (auto & component : components)
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
