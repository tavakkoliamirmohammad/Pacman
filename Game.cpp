#include "Game.h"
#include "YellowScore.h"
#include "BlueScore.h"
#include "Ghost.h"
#include "Map.h"
#include "Wall.h"
#include "GameState.h"
#include <iostream>
#include <ctime>
#include <string>

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
        pair<float, float> point = getRandomPosition();
        ghost->setPosition(point.first, point.second);
        components.push_back(ghost);
        GameState::ghosts.push_back(ghost);
    }

    for (int i = 0; i < 6; i++) {
        Score *score = new YellowScore(this);
        pair<float, float> point = getRandomPosition();
        score->setPosition(point.first, point.second);
        GameState::scores.push_back(score);
        components.push_back(score);
    }
    for (int i = 0; i < 6; i++) {
        Score *score = new BlueScore(this);
        pair<float, float> point = getRandomPosition();
        score->setPosition(point.first, point.second);
        GameState::scores.push_back(score);
        components.push_back(score);
    }
    pair<float, float> point = getRandomPosition();
    this->main_character->setPosition(point.first, point.second);
    GameState::pacmans.push_back(this->main_character);

    for (auto &component : components)
        component->load(time1);
}

pair<float, float> Game::getRandomPosition() {
    float x = ((double) rand() / (RAND_MAX)) * 25;
    float y = ((double) rand() / (RAND_MAX)) * 25;
    while (GameState::isPositionBlocked(x * 40, y * 40)) {
        x = ((double) rand() / (RAND_MAX)) * 25;
        y = ((double) rand() / (RAND_MAX)) * 25;
    }
    return make_pair(x * 40, y * 40);
}

void Game::update(int time) {
    for (auto &component : components)
        component->update(time);
    Score *score;
    Ghost *ghost;
    bool score_found = false;
    for (auto iter = components.begin(); iter != components.end(); iter++) {
        score_found = false;
        if ((score = dynamic_cast<Score *>(*iter)) != nullptr) {
            if (abs(main_character->getX() - score->getX()) < 25 && abs(main_character->getY() - score->getY()) < 25) {
                components.erase(iter--);
                this->score += score->getScore();
            }
            score_found = true;
        } else if ((ghost = dynamic_cast<Ghost *>(*iter)) != nullptr) {
            if (abs(main_character->getX() - ghost->getX()) < 25 && abs(main_character->getY() - ghost->getY()) < 25) {
                components.erase(iter--);
                gameState = GameRunningState::GAME_OVER;
            }
        }
    }
    if(!score_found){
        gameState = GameRunningState::WIN;
    }
}

void Game::showText(float r, float g, float b, int x, int y, string text, void *font) {
    glColor4f(r, g, b, 1);
    glRasterPos2f(x, y);
    for (char i : text) {
        glutBitmapCharacter(font, i);
    }
}

void Game::render(int time) {
    if (gameState == GameRunningState::GAME_OVER) {
        showText(1, 0, 0, 500, 500, "GAME OVER!", GLUT_BITMAP_TIMES_ROMAN_24);
        return;
    }

    if (gameState == GameRunningState::WIN) {
        showText(1, 1, 0, 450, 500, "YOU ARE THE WINNER!", GLUT_BITMAP_TIMES_ROMAN_24);
        return;
    }else{
        showText(1, 0, 0, 1050, 900, "TOTAL SCORE", GLUT_BITMAP_HELVETICA_18);
        showText(1, 0, 1, 1150, 850, to_string(game->score), GLUT_BITMAP_TIMES_ROMAN_24);
        showText(0, 1, 0, 1050, 600, "Press R to rest", GLUT_BITMAP_HELVETICA_18);
        showText(0, 1, 0, 1050, 650, "Press q to quit", GLUT_BITMAP_HELVETICA_18);
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        for (auto &component : components)
            component->render(time);
        glDisable(GL_TEXTURE_2D);
    }
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

void Game::keyboardFunc(char key) {
    if (key == 'q') {
        exit(0);
    } else if (key == 'r') {
        reset();
    }
}

void Game::reset() {
    GameState::pacmans.clear();
    GameState::walls.clear();
    GameState::ghosts.clear();
    GameState::scores.clear();
    components.clear();
    int time = glutGet(GLUT_ELAPSED_TIME);
    load(time);
}