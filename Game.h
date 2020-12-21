#pragma once

#include <vector>
#include "Component.h"
#include "Pacman.h"
#include "Wall.h"
#include <string>

class Game : public Component {
public:
    Game();

    ~Game();

    void load(int time1);

    void update(int time);

    void render(int time);

    void keyboard(int time, int key, int x, int y);

    void keyboard_up(int time, int key, int x, int y);

    void keyboardFunc(char key);


private:
    enum GameRunningState {
        RUNNING, GAME_OVER, WIN
    };

    static pair<float, float> getRandomPosition();

    static void showText(float r, float g, float b, int x, int y, string text, void *font);

    Pacman *main_character;
    GameRunningState gameState = GameRunningState::RUNNING;
    int score = 0;
    std::vector<Component *> components;

    void reset();
};