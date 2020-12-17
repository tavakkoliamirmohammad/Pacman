#pragma once

#include <cstdlib>
#include <GL/glut.h>

class Game;

class Component {
public:

    Component(Component *parent);

    void virtual load(int time);

    void virtual update(int time) = 0;

    void virtual render(int time) = 0;

protected:

    int created_time;
    Game *game;
    Component *parent_component;

    friend class Game;
};