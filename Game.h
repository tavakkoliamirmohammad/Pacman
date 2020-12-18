#pragma once

#include <vector>
#include "Component.h"
#include "Pacman.h"
#include "Wall.h"

class Game : public Component {
public:
    Game();

    ~Game();

    void load(int time1);

    void update(int time);

    void render(int time);

    void keyboard(int time, int key, int x, int y);

    void keyboard_up(int time, int key, int x, int y);


private:
    static pair<float, float> getRandomPosition();

    Pacman *main_character;
    int score = 0;
    std::vector<Component *> components;
};